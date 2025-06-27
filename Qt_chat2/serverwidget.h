#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>

class QTcpServer;
class QTcpSocket;
class QFile;
class QProgressDialog;
class QLabel;

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void onStartServerClicked();
    void acceptConnection();
    void readClient();

private:
    QLabel* infoLabel;
    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QFile *newFile;
    QProgressDialog* progressDialog;

    QByteArray inBlock;
    QString filename;
    qint64 totalSize;
    qint64 bytesReceived;
};

#endif // SERVERWIDGET_H
