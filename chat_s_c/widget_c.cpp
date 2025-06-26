#include "widget_c.h" // ClientWidget 클래스 정의를 위해 포함

#include <QtWidgets> // QLineEdit, QPushButton, QTextEdit, QHBoxLayout, QVBoxLayout
#include <QtNetwork> // QTcpSocket
#include <QApplication> // qApp 사용을 위해 포함
#include <QRegularExpression> // QRegularExpression, QRegularExpressionValidator
#include <QDebug> // qDebug() 사용을 위해 포함

#define BLOCK_SIZE 1024

ClientWidget::ClientWidget(QWidget *parent) : QWidget(parent) { // 클래스 이름 변경
    // 연결한 서버 정보 입력을 위한 위젯들
    QLineEdit *serverAddress = new QLineEdit(this);
    serverAddress->setText("127.0.0.1");
    serverAddress->setPlaceholderText("Server IP Address");
    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(re, this); // validator 생성 시 부모 지정
    serverAddress->setValidator(validator);
    // serverAddress->setInputMask("999.999.999.999;_"); // 마스크는 유효성 검사와 함께 사용 시 주의

    QLineEdit *serverPort = new QLineEdit(this);
    serverPort->setInputMask("00000;_");
    serverPort->setPlaceholderText("Server Port No");

    QPushButton *connectButton = new QPushButton("connect", this);
    connect(connectButton, &QPushButton::clicked,
            [=]{ clientSocket->connectToHost(serverAddress->text(),
                                              serverPort->text().toInt()); });

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addStretch(1);
    serverLayout->addWidget(serverAddress);
    serverLayout->addWidget(serverPort);
    serverLayout->addWidget(connectButton);

    message = new QTextEdit(this);              // 서버에서 오는 메시지 표시용
    message->setReadOnly(true);

    // 서버로 보낼 메시지를 위한 위젯들
    inputLine = new QLineEdit(this);
    QPushButton *sentButton = new QPushButton("Send", this);
    connect(sentButton, &QPushButton::clicked, this, &ClientWidget::sendData); // 최신 Qt 문법으로 변경

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(inputLine);
    inputLayout->addWidget(sentButton);

    // 종료 기능
    QPushButton *quitButton = new QPushButton("Quit", this);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit); // 최신 Qt 문법으로 변경

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(serverLayout);
    mainLayout->addWidget(message);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    clientSocket = new QTcpSocket(this);       // 클라이언트 소켓 생성
    connect(clientSocket, &QAbstractSocket::errorOccurred,
            [=](QAbstractSocket::SocketError socketError){ // 람다 함수에 매개변수 추가
                Q_UNUSED(socketError); // 사용하지 않는 매개변수 경고 제거
                qDebug() << clientSocket->errorString();
            });
    connect(clientSocket, &QTcpSocket::readyRead, this, &ClientWidget::echoData); // 최신 Qt 문법으로 변경
    setWindowTitle(tr("Echo Client"));
}

ClientWidget::~ClientWidget() // 클래스 이름 변경
{
    clientSocket->close();
}

void ClientWidget::echoData() // 클래스 이름 변경, 대소문자 일치
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender());
    if (!clientSocket) return; // nullptr 체크 추가

    // bytesAvailable()가 BLOCK_SIZE보다 크면 한 번에 다 읽지 못할 수 있으므로,
    // 현재 사용 가능한 모든 데이터를 읽도록 수정하는 것이 좋습니다.
    if (clientSocket->bytesAvailable() > BLOCK_SIZE) {
        // 이 부분도 ServerWidget::echoData()와 마찬가지로 개선을 고려하세요.
    }
    QByteArray bytearray = clientSocket->readAll(); // read(BLOCK_SIZE) 대신 readAll() 사용
    message->append(QString(bytearray));
}

void ClientWidget::sendData() // 클래스 이름 변경
{
    QString str = inputLine->text();
    if(str.length()) {
        QByteArray bytearray;
        bytearray = str.toUtf8();
        clientSocket->write(bytearray);
        inputLine->clear(); // 메시지 전송 후 입력창 비우기
    }
}
