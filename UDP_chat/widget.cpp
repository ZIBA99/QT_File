#include "widget.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QHostAddress>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    infoLabel = new QLabel("받은 메시지: ", this);
    QPushButton* button = new QPushButton("Send", this);
    message = new QLineEdit(this);

    // [개선됨] 최신 시그널/슬롯 문법 사용
    connect(button, &QPushButton::clicked, this, &Widget::sendData);
    connect(message, &QLineEdit::returnPressed, this, &Widget::sendData);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(infoLabel);
    layout->addStretch(1);
    layout->addWidget(message);
    layout->addWidget(button);
    setLayout(layout);

    // UDP 소켓 설정
    m_udpSocket = new QUdpSocket(this);

    // [개선됨] 최신 시그널/슬롯 문법 사용
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &Widget::processPendingDatagrams);

    // 멀티캐스트 설정
    // 멀티캐스트 주소는 D 클래스 IP 주소 (224.0.0.0 ~ 239.255.255.255)
    QHostAddress multicastAddress("225.0.0.2");

    // 포트를 여러 프로그램이 함께 사용할 수 있도록 ShareAddress 플래그 사용
    m_udpSocket->bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);

    // 지정된 멀티캐스트 그룹에 가입하여 메시지를 수신할 수 있도록 함
    m_udpSocket->joinMulticastGroup(multicastAddress);

    // 멀티캐스트 TTL(Time-To-Live) 설정 (1은 동일 서브넷 내에서만 전파됨을 의미)
    m_udpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, 1);

    setWindowTitle("UDP Multicast Chat");
}

Widget::~Widget()
{
}

void Widget::sendData()
{
    QByteArray data;
    // [개선됨] 안전하고 현대적인 방법으로 QString을 QByteArray로 변환
    data = message->text().toUtf8();

    if (data.isEmpty()) {
        return;
    }

    QHostAddress multicastAddress("225.0.0.2");
    quint16 port = 45454;

    // 데이터그램을 멀티캐스트 주소로 전송
    m_udpSocket->writeDatagram(data, multicastAddress, port);

    message->clear();
    message->setFocus();
}

void Widget::processPendingDatagrams()
{
    // [개선됨] 한 번의 시그널에 여러 데이터그램이 도착할 수 있으므로, 루프 처리
    while (m_udpSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = m_udpSocket->receiveDatagram();

        // 내가 보낸 메시지는 표시하지 않음 (선택 사항)
        if (datagram.senderAddress() == m_udpSocket->localAddress() && datagram.senderPort() == m_udpSocket->localPort()) {
            continue;
        }

        qDebug() << "Message From :: " << datagram.senderAddress().toString();
        qDebug() << "Port From :: " << datagram.senderPort();
        qDebug() << "Message :: " << datagram.data();

        infoLabel->setText("받은 메시지: " + QString::fromUtf8(datagram.data()));
    }
}
