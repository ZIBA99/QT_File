#include <QApplication>
#include "widget.h"    // ServerWidget
#include "widget_c.h"  // ClientWidget

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 서버 실행
    ServerWidget server;
    server.show();

    // 클라이언트 실행
    ClientWidget client;
    client.show();

    return a.exec();
}
