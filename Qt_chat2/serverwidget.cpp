#include "serverwidget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressDialog>
#include <QDataStream>
#include <QDebug>

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent), tcpServer(nullptr), clientSocket(nullptr), newFile(nullptr),
    totalSize(0), bytesReceived(0)
{
    setWindowTitle("파일 수신 서버");
    infoLabel = new QLabel("서버가 시작되지 않았습니다.", this);
    QPushButton* button = new QPushButton("서버 시작", this);
    connect(button, &QPushButton::clicked, this, &ServerWidget::onStartServerClicked);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addWidget(button);
    setLayout(layout);

    progressDialog = new QProgressDialog(this);
    progressDialog->setAutoClose(true);
    progressDialog->setCancelButton(nullptr);
}

ServerWidget::~ServerWidget()
{
    if (newFile && newFile->isOpen()) {
        newFile->close();
        delete newFile;
    }
}

void ServerWidget::onStartServerClicked()
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &ServerWidget::acceptConnection);

    if (!tcpServer->listen(QHostAddress::Any, 8100)) {
        infoLabel->setText("서버를 시작할 수 없습니다: " + tcpServer->errorString());
        return;
    }
    infoLabel->setText("서버 시작됨. 클라이언트 연결 대기 중...");
    sender()->deleteLater(); // "서버 시작" 버튼은 한 번만 누르도록 제거
}

void ServerWidget::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    if (!clientSocket) return;

    connect(clientSocket, &QTcpSocket::readyRead, this, &ServerWidget::readClient);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);

    infoLabel->setText("클라이언트 연결됨, 파일 수신 준비 중...");
    bytesReceived = 0;
    progressDialog->reset();
}

void ServerWidget::readClient()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_15);

    if (bytesReceived == 0) {
        if (clientSocket->bytesAvailable() < sizeof(qint64) + sizeof(qint64))
            return;

        in >> totalSize >> bytesReceived; // 헤더에서 전체 크기와 파일 이름 크기를 읽음

        if (clientSocket->bytesAvailable() < bytesReceived)
            return;

        in >> filename;

        QFileInfo info(filename);
        QString currentFileName = info.fileName();
        newFile = new QFile(currentFileName);
        if (!newFile->open(QFile::WriteOnly)) {
            qDebug() << "파일을 열 수 없습니다.";
            return;
        }

        infoLabel->setText(tr("%1 파일 수신 중...").arg(currentFileName));
        progressDialog->setMaximum(totalSize);
        progressDialog->setValue(0);
        progressDialog->show();

        bytesReceived = 0; // 실제 파일 내용을 받기 위해 초기화
    }

    bytesReceived += newFile->write(clientSocket->readAll());
    progressDialog->setValue(bytesReceived);

    if (bytesReceived == totalSize) {
        infoLabel->setText(tr("%1 파일 수신 완료").arg(filename));
        progressDialog->hide();
        newFile->close();
        delete newFile;
        newFile = nullptr;
        clientSocket->close();
    }
}
