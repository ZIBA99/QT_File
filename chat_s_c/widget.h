#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTcpServer>
#include <QTcpSocket> // QTcpSocket을 사용하므로 추가

class ServerWidget : public QWidget {
    Q_OBJECT
public:
    explicit ServerWidget(QWidget *parent = nullptr); // explicit 키워드 추가, nullptr 사용
    // ~ServerWidget(); // 소멸자가 필요하다면 여기에 선언

private slots:
    void clientConnect();
    void echoData();

private:
    QLabel *infolabel;
    QTcpServer *tcpserver;
};

#endif // WIDGET_H
