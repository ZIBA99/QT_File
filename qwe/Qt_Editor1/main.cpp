/*#include "qteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtEditor w;
    w.show();
    return a.exec();
}*/


#include <QApplication>
#include "qteditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QtEditor 객체 생성
    QtEditor editor;
    editor.setWindowTitle("이게 실습인가용"); // 창 제목 설정
    editor.resize(800, 600); // 창 크기 설정
    editor.show(); // 창 표시

    return a.exec(); // 애플리케이션 실행
}


