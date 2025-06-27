#include "clientwidget.h"
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QByteArray>
#include <QDataStream>
#include <QProgressDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent), file(nullptr), totalSize(0)
{
    setWindowTitle("파일 전송 클라이언트");
    infoLabel = new QLabel("전송할 파일을 선택하세요.", this);
    sendButton = new QPushButton("파일 전송", this);
    QPushButton *openButton = new QPushButton("파일 열기", this);
    sendButton->setEnabled(false);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addWidget(openButton);
    layout->addWidget(sendButton);
    setLayout(layout);

    tcpClient = new QTcpSocket(this);
    progressDialog = new QProgressDialog(this);
    progressDialog->setAutoClose(true);
    progressDialog->setCancelButton(nullptr);

    connect(openButton, &QPushButton::clicked, this, &ClientWidget::openFile);
    connect(sendButton, &QPushButton::clicked, this, &ClientWidget::sendFile);
    connect(tcpClient, &QTcpSocket::connected, this, &ClientWidget::onConnected);
    connect(tcpClient, &QTcpSocket::bytesWritten, this, &ClientWidget::updateProgress);
}

ClientWidget::~ClientWidget()
{
    if (file && file->isOpen()) {
        file->close();
        delete file;
    }
}

void ClientWidget::openFile()
{
    filename = QFileDialog::getOpenFileName(this);
    if (filename.isEmpty()) return;

    if (file) {
        file->close();
        delete file;
    }
    file = new QFile(filename);

    totalSize = file->size();
    infoLabel->setText(tr("파일 준비 완료: %1").arg(QFileInfo(filename).fileName()));
    sendButton->setEnabled(true);
}

void ClientWidget::sendFile()
{
    if (!file) return;

    sendButton->setEnabled(false);
    tcpClient->connectToHost(QHostAddress("127.0.0.1"), 8100);
    progressDialog->show();
}

void ClientWidget::onConnected()
{
    infoLabel->setText("서버 연결됨. 전송 시작...");

    if (!file->open(QFile::ReadOnly)) {
        infoLabel->setText("파일을 읽을 수 없습니다.");
        return;
    }

    bytesWritten = 0;
    bytesToWrite = totalSize;

    // 헤더 전송: [전체 크기][파일 이름 크기][파일 이름]
    outBlock.clear();
    QDataStream out(&outBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);

    QString currentFileName = QFileInfo(filename).fileName();
    out << qint64(0) << qint64(0) << currentFileName;
    totalSize += outBlock.size();
    out.device()->seek(0);
    out << totalSize << qint64(outBlock.size() - sizeof(qint64) * 2);

    bytesWritten = tcpClient->write(outBlock);
    progressDialog->setMaximum(totalSize);
    progressDialog->setValue(bytesWritten);
}

void ClientWidget::updateProgress(qint64 numBytes)
{
    bytesWritten += numBytes;

    if (bytesToWrite > 0) {
        outBlock = file->read(qMin(bytesToWrite, (qint64)64 * 1024));
        bytesToWrite -= tcpClient->write(outBlock);
        outBlock.clear();
    }

    progressDialog->setValue(bytesWritten);

    if (bytesWritten == totalSize) {
        infoLabel->setText(tr("파일 전송 완료!"));
        file->close();
        delete file;
        file = nullptr;
        sendButton->setEnabled(true);
        progressDialog->hide();
    }
}
