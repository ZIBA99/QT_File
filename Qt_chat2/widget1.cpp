#include "widget1.h"
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QDataStream>
#include <QProgressDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
{
    infoLabel = new QLabel("전송할 파일을 선택하세요.", this);
    sendButton = new QPushButton("파일 전송", this);
    QPushButton *openButton = new QPushButton("파일 열기", this);

    // [수정됨] 처음에는 전송 버튼 비활성화
    sendButton->setEnabled(false);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addWidget(openButton);
    layout->addWidget(sendButton);
    setLayout(layout);

    tcpClient = new QTcpSocket(this);
    progressDialog = new QProgressDialog(this); // [수정됨] 부모 지정
    progressDialog->setAutoClose(true);
    progressDialog->setCancelButton(nullptr);

    // [수정됨] 최신 시그널/슬롯 문법 및 로직 수정
    connect(openButton, &QPushButton::clicked, this, &ClientWidget::openFile);
    connect(sendButton, &QPushButton::clicked, this, &ClientWidget::sendFile);
    connect(tcpClient, &QTcpSocket::connected, this, &ClientWidget::onConnected);
    connect(tcpClient, &QTcpSocket::bytesWritten, this, &ClientWidget::updateProgress);
}

ClientWidget::~ClientWidget()
{
    if (file && file->isOpen()) {
        file->close();
    }
    delete file;
}

void ClientWidget::openFile()
{
    filename = QFileDialog::getOpenFileName(this);
    if (filename.isEmpty()) return;

    file = new QFile(filename);
    if (!file->open(QFile::ReadOnly)) {
        infoLabel->setText("파일을 열 수 없습니다.");
        return;
    }

    totalSize = file->size();
    infoLabel->setText(tr("파일 준비 완료: %1").arg(QFileInfo(filename).fileName()));
    sendButton->setEnabled(true); // 파일이 선택되면 버튼 활성화
}

void ClientWidget::sendFile()
{
    if (!file) return;

    // 연결 시도
    tcpClient->connectToHost(QHostAddress("127.0.0.1"), 8100);
    progressDialog->show();
    sendButton->setEnabled(false); // 전송 중에는 버튼 비활성화
}

// [추가됨] 연결이 성공하면 호출됨
void ClientWidget::onConnected()
{
    infoLabel->setText("서버 연결됨. 전송 시작...");
    bytesWritten = 0;
    // 헤더부터 전송
    sendHeader();
}

// [수정됨] 헤더 전송 로직
void ClientWidget::sendHeader()
{
    outBlock.clear();
    QDataStream out(&outBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_15);

    // [수정됨] 헤더 구조를 단순화하고 명확하게 만듦
    // 전체 크기(파일 크기), 파일 이름 순으로 보냄
    out << qint64(totalSize) << QFileInfo(filename).fileName();

    bytesToWrite = totalSize + outBlock.size(); // 총 보낼 바이트 수 (헤더 + 파일)

    // 헤더를 먼저 보냄
    tcpClient->write(outBlock);

    progressDialog->setMaximum(bytesToWrite);
    progressDialog->setValue(outBlock.size());
}

// [수정됨] 파일 내용 전송 및 진행 상황 업데이트
void ClientWidget::updateProgress(qint64 numBytes)
{
    bytesWritten += numBytes;
    progressDialog->setValue(bytesWritten);

    if (bytesToWrite > 0) { // 보낼 데이터가 남았다면
        outBlock = file->read(qMin(bytesToWrite, (qint64)64*1024));
        bytesToWrite -= tcpClient->write(outBlock);
        outBlock.clear();
    }

    if (bytesWritten == totalSize + qint64(sizeof(qint64)) + qint64(sizeof(QString))) { // [수정필요]
        // 이 부분의 종료 조건이 복잡해져서, 아래와 같이 간단하게 수정
    }

    if (bytesWritten >= totalSize) { // 파일 내용 전송이 완료되면
        if (file->atEnd()) {
            infoLabel->setText(tr("파일 전송 완료!"));
            progressDialog->hide();
            file->close();
            delete file;
            file = nullptr;
            sendButton->setEnabled(true);
        }
    }
}
