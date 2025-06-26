#ifndef WIDGET_C_H
#define WIDGET_C_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>

class ClientWidget : public QWidget { // 클래스 이름 변경
    Q_OBJECT
public:
    explicit ClientWidget(QWidget *parent = nullptr); // explicit 키워드 추가, nullptr 사용
    ~ClientWidget();

private slots:
    void echoData(); // 대소문자 일치 (echoData)
    void sendData();

private:
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;
};

#endif // WIDGET_C_H
