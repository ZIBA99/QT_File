#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>

class QTcpSocket;
class QFile;
class QProgressDialog;
class QLabel;
class QPushButton;

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void openFile();
    void sendFile();
    void onConnected();
    void updateProgress(qint64 numBytes);

private:
    QLabel* infoLabel;
    QPushButton *sendButton;
    QTcpSocket *tcpClient;
    QFile* file;
    QString filename;
    QProgressDialog* progressDialog;

    qint64 totalSize;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    QByteArray outBlock;
};

#endif // CLIENTWIDGET_H
