#include <QApplication>
#include "widget_c.h"  // ClientWidget 클래스 포함

int main_c(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWidget w;  // ClientWidget 인스턴스 생성
    w.show();
    return a.exec();
}
