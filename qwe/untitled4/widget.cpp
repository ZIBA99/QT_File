#include "widget.h"
//4-1
/*
#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* pushButton1 = new QPushButton();
    pushButton1->setText("Button1");
    QPushButton* pushButton2 = new QPushButton("Button2");
    QPushButton* pushButton3 = new QPushButton("Button3",this);

    QHBoxLayout* hBoxLayout = new QHBoxLayout;
    hBoxLayout -> setContentsMargins(0,0,0,0);
    hBoxLayout -> addWidget(pushButton1);
    hBoxLayout -> addWidget(pushButton2);
    hBoxLayout -> addWidget(pushButton3);
    setLayout(hBoxLayout);
}

Widget::~Widget() {}*/

//4-2
/*
#include "widget.h"
#include <QVBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button1 = new QPushButton();
    button1->setText("Button1");  // ✅ 변수명 수정
    QPushButton* button2 = new QPushButton("Button2");
    QPushButton* button3 = new QPushButton("Button3", this);

    QVBoxLayout* vBoxLayout = new QVBoxLayout;
    vBoxLayout->setContentsMargins(10, 10, 10, 10);  // 여백 설정
    vBoxLayout->setSpacing(6);  // 버튼 사이 간격 설정
    vBoxLayout->addWidget(button1);
    vBoxLayout->addWidget(button2);
    vBoxLayout->addWidget(button3);

    setLayout(vBoxLayout);  // 현재 Widget에 레이아웃 적용
}

Widget::~Widget() {}*/

//4-3 QGridLayout class
/*
#include <QGridLayout>
#include <QPushButton>
#define NO_OF_ROW 3

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* gridLayout = new QGridLayout;
    QPushButton* pushButton[NO_OF_ROW* NO_OF_ROW];
    for(int y = 0;y<NO_OF_ROW;y++){
        for(int x=0;x<NO_OF_ROW;x++){
            int p= x+y* NO_OF_ROW;
            QString str = QString("Button%1").arg(p+1);
            pushButton[p] =new QPushButton(str,this);
            gridLayout-> addWidget(pushButton[p],x,y);
        }
    }
    setLayout(gridLayout);
}

Widget::~Widget() {}*/

//4-4
/*
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QDial>
#include <QLabel>
#include <QCalendarWidget>
#include <QTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDial* dial = new QDial(this);
    dial ->setRange(0,2);

    QLabel* label = new QLabel("Stack1",this);
    QCalendarWidget* calenderWidget = new QCalendarWidget(this);
    QTextEdit* textEdit = new QTextEdit("Stack3",this);
    QStackedLayout* stackedLayout = new QStackedLayout();// 주의!!!!!!
    stackedLayout -> addWidget(label);
    stackedLayout -> addWidget(calenderWidget);
    stackedLayout -> addWidget(textEdit);

    connect(dial,&QDial::valueChanged,stackedLayout,&QStackedLayout::setCurrentIndex);

    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout -> addWidget(dial);
    hBoxLayout -> addLayout(stackedLayout);

    setLayout(hBoxLayout);


}*/
//4-4 수정 후
// widget.cpp
/*
#include "widget.h"
#include <QDial>
#include <QLabel>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QStackedLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QDial* dial = new QDial(this);
    dial->setRange(0, 2);

    QLabel* label = new QLabel("Stack1", this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this);
    QTextEdit* textEdit = new QTextEdit("Stack3", this);
    QStackedLayout* stackedLayout = new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial, &QDial::valueChanged, stackedLayout, &QStackedLayout::setCurrentIndex);

    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    setLayout(hBoxLayout);
}*/

//4-6 QGroupBox
/*
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QStringList>
#include <QWidget>

// 커스텀 위젯 클래스 생성자
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 라벨 문자열 리스트 생성
    QStringList labels;
    labels << "&IP Address" << "&Mac Address" << "&Data";

    // 3개의 QLineEdit 포인터 배열
    QLineEdit* lineEdit[3];

    // 폼 레이아웃 생성
    QFormLayout* formLayout = new QFormLayout;

    // 라벨과 라인 에디트를 폼 레이아웃에 추가
    for(int i = 0; i < 3; i++) {
        lineEdit[i] = new QLineEdit(this);
        formLayout->addRow(labels.at(i), lineEdit[i]);
    }

    // 그룹박스 생성 및 폼 레이아웃 지정
    QGroupBox* groupBox = new QGroupBox("&Widget Group", this);
    groupBox->move(5, 5);  // 위치 설정
    groupBox->setLayout(formLayout);

    // 위젯 크기 설정 (그룹박스 크기에 여유 여백 추가)
    resize(groupBox->sizeHint().width() + 10, groupBox->sizeHint().height() + 10);
}

// 소멸자 정의
Widget::~Widget() {}*/


//4-7 QTabWidget
/*
#include <QTabWidget>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QVBoxLayout> // 레이아웃을 직접 쓰고 싶을 때 필요

// 위젯 클래스 생성자
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 각각의 탭에 넣을 위젯 생성
    QDial* dial = new QDial(this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this); // 오타: calender → calendar
    QTextEdit* textEdit = new QTextEdit("Tab 3", this);

    // 탭 위젯 생성
    QTabWidget* tabWidget = new QTabWidget(this);
    tabWidget->addTab(dial, "Tab &1");             // 첫 번째 탭
    tabWidget->addTab(calendarWidget, "Tab &2");   // 두 번째 탭
    tabWidget->addTab(textEdit, "Tab &3");         // 세 번째 탭

    // 탭 위젯을 레이아웃에 추가 (안 써도 되지만 구조적으로 더 안전)
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);
    setLayout(layout);

    // 창 크기를 탭 위젯 크기에 맞춰 조절
    resize(tabWidget->sizeHint());
}
Widget::~Widget() {}
*/


//4-9 수정 전
/*
#include <QTabWidget>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>
#include <QDial>


// 위젯 클래스 생성자
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 각각의 탭에 넣을 위젯 생성
    QDial* dial = new QDial(this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this); // 오타: calender → calendar
    QTextEdit* textEdit = new QTextEdit("Tab 3", this);

    // 탭 위젯 생성
    QTabWidget* tabWidget = new QTabWidget(this);
    tabWidget->addTab(dial, "Tab &1");             // 첫 번째 탭
    tabWidget->addTab(calendarWidget, "Tab &2");   // 두 번째 탭
    tabWidget->addTab(textEdit, "Tab &3");         // 세 번째 탭

    // 탭 위젯을 레이아웃에 추가 (안 써도 되지만 구조적으로 더 안전)
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);
    setLayout(layout);

    QLabel* label = new QLabel("&Value",this);
    QDial* dial1 = new QDial(this);
    QDial* dial2 = new QDial(this);
    label -> setBuddy(dial2);

    QSlider* splitter = new QSplitter(this);
    splitter -> addWidget(label);
    splitter -> addWidget(dial1);
    splitter -> addWidget(dial2);

    resize(tabWidget->sizeHint());
}
Widget::~Widget() {}*/

//4-9
#include "widget.h"
#include <QTabWidget>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 각각의 탭에 넣을 위젯 생성
    QDial* dial = new QDial(this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this);
    QTextEdit* textEdit = new QTextEdit("Tab 3", this);

    // 탭 위젯 생성 및 위젯 추가
    QTabWidget* tabWidget = new QTabWidget(this);
    tabWidget->addTab(dial, "Tab &1");
    tabWidget->addTab(calendarWidget, "Tab &2");
    tabWidget->addTab(textEdit, "Tab &3");

    // 아래에 추가로 배치할 컨트롤 그룹 생성
    QLabel* label = new QLabel("&Value", this);
    QDial* dial1 = new QDial(this);
    QDial* dial2 = new QDial(this);
    label->setBuddy(dial2); // Alt+V로 dial2 포커스 이동 가능

    // 수평 방향의 QSplitter 생성
    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(label);
    splitter->addWidget(dial1);
    splitter->addWidget(dial2);

    // 전체 레이아웃 구성
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);  // 상단 탭 위젯
    layout->addWidget(splitter);   // 하단 분할 뷰
    setLayout(layout);

    // 창 크기 조절
    resize(400, 400);
}

Widget::~Widget() {}



