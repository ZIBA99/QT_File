#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include "qpushbutton.h"
#include <QWidget>

// Forward declarations
class QTcpSocket;
class QFile;
class QProgressDialog;
class QLabel;

class ClientWidget : public QWidget // [수정됨] 클래스 이름 변경
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void openFile();
    void sendFile();
    void onConnected();       // [추가됨] 연결 성공 시 호출될 슬롯
    void updateProgress(qint64 numBytes);

private:
    void sendHeader(); // [추가됨] 헤더 전송 로직 분리

    QLabel* infoLabel;
    QPushButton *sendButton; // [추가됨] 버튼 멤버 변수
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
