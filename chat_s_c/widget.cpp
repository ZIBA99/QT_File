#include "widget.h" // ServerWidget 클래스 정의를 위해 포함

#include <QtWidgets> // QLabel, QPushButton, QHBoxLayout, QVBoxLayout, QMessageBox
#include <QtNetwork> // QTcpServer, QTcpSocket
#include <QApplication> // qApp 사용을 위해 포함

#define BLOCK_SIZE 1024

ServerWidget::ServerWidget(QWidget *parent) : QWidget(parent)
{
    infolabel = new QLabel(this);
    QPushButton *quitButton = new QPushButton("Quit", this);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit); // 최신 Qt 문법으로 변경

    QHBoxLayout *buttonlayout = new QHBoxLayout;
    buttonlayout->addStretch(1);
    buttonlayout->addWidget(quitButton);

    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->addWidget(infolabel);
    mainlayout->addLayout(buttonlayout);
    setLayout(mainlayout);

    tcpserver = new QTcpServer(this);
    connect(tcpserver, &QTcpServer::newConnection, this, &ServerWidget::clientConnect); // 최신 Qt 문법으로 변경
    if (!tcpserver->listen()){
        QMessageBox::critical(this, tr("Echo Server"),
                              tr("Unable to start the server: %1.")
                                  .arg(tcpserver->errorString()));
        close();
        return;
    }

    infolabel->setText(tr("The server is running on port %1.").arg(tcpserver->serverPort()));
    setWindowTitle(tr("Echo Server"));
}

void ServerWidget::clientConnect()
{
    QTcpSocket* clientConnection = tcpserver->nextPendingConnection();
    connect(clientConnection, &QTcpSocket::disconnected,
            clientConnection, &QTcpSocket::deleteLater); // 최신 Qt 문법으로 변경
    connect(clientConnection, &QTcpSocket::readyRead, this, &ServerWidget::echoData); // 최신 Qt 문법으로 변경
    infolabel->setText("new connection is established...");
}

void ServerWidget::echoData()
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket*>(sender());
    if (!clientConnection) return; // nullptr 체크 추가

    // bytesAvailable()가 BLOCK_SIZE보다 크면 한 번에 다 읽지 못할 수 있으므로,
    // 현재 사용 가능한 모든 데이터를 읽도록 수정하는 것이 좋습니다.
    // 여기서는 기존 로직을 유지하되, 실제 사용 시에는 개선을 고려하세요.
    if(clientConnection->bytesAvailable() > BLOCK_SIZE) {
        // 이 부분은 실제로는 더 많은 데이터를 처리해야 할 수 있습니다.
        // 예를 들어, QDataStream을 사용하여 패킷 단위로 처리하거나,
        // 모든 데이터를 읽어올 때까지 반복하는 로직이 필요할 수 있습니다.
    }
    QByteArray bytearray = clientConnection->readAll(); // read(BLOCK_SIZE) 대신 readAll() 사용
    clientConnection->write(bytearray);
    infolabel->setText(QString(bytearray));
}
