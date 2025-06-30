//4-1,4-2
/*
#include <QApplication>
#include "widget.h"  // 위에서 작성한 Widget 클래스 헤더 포함

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // Qt 애플리케이션 객체 생성

    Widget window;                 // Widget 클래스 인스턴스 생성
    window.setWindowTitle("Qt Widget Example");
    window.resize(300, 100);       // 창 크기 설정
    window.show();                 // 창 보이기

    return app.exec();             // 이벤트 루프 실행
}*/

//4-3
/*
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // Qt 애플리케이션 초기화

    Widget window;                 // 사용자 정의 Widget 인스턴스 생성
    window.setWindowTitle("QGridLayout Example");
    window.resize(300, 300);       // 창 크기 설정 (필요에 따라 조정)
    window.show();                 // 창 보이기

    return app.exec();             // 이벤트 루프 실행
}*/

//4-4
/*
#include <QApplication>
#include "widget.h"  // 위젯 클래스 정의가 있는 헤더 파일

int main(int argc, char *argv[])
{
    // QApplication 객체 생성 (Qt 애플리케이션 실행을 위한 필수 객체)
    QApplication app(argc, argv);

    // 사용자 정의 Widget 객체 생성 및 표시
    Widget w;
    w.show(); // 화면에 위젯을 보이게 함

    // 이벤트 루프 실행 (사용자가 종료할 때까지 계속 실행됨)
    return app.exec();
}*/


//4-6
/*
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget w;
    w.show();

    return app.exec();
}*/

//4-7
/*
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget w;
    w.show();
    return app.exec();
}*/


//4-8 QToolBox

#include <QApplication>
#include <QToolBox>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    // Qt 애플리케이션 객체 생성 (이벤트 루프, GUI 구성에 필수)
    QApplication app(argc, argv);

    // QToolBox 생성 (접이식 메뉴처럼 페이지를 전환할 수 있는 위젯)
    QToolBox toolbox;
    toolbox.resize(300, 380); // 툴박스 크기 설정
    toolbox.show();           // 화면에 표시

    // 첫 번째 페이지: QDial (다이얼)
    QDial dial(&toolbox); // 부모를 toolbox로 설정
    toolbox.addItem(&dial, "Page &1"); // "&"는 키보드 단축키 의미

    // 두 번째 페이지: QCalendarWidget (달력)
    QCalendarWidget calendarWidget(&toolbox); // 오타 주의: calendar
    toolbox.addItem(&calendarWidget, "Page &2");

    // 세 번째 페이지: QTextEdit (텍스트 입력창)
    QTextEdit textEdit("QTextEdit", &toolbox); // 초기 텍스트 포함
    toolbox.addItem(&textEdit, "Page &3");

    // 이벤트 루프 실행 (GUI 유지)
    return app.exec();
}


