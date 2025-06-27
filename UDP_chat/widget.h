#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// Forward declarations
class QUdpSocket;
class QLabel;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void sendData();
    void processPendingDatagrams();

private:
    QLabel *infoLabel;
    QLineEdit *message;
    QUdpSocket *m_udpSocket;
};

#endif // WIDGET_H
