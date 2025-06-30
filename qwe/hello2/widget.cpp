//2-1
/*
#include <QApplication>
#include <QPushButton>

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit",this);
    quit->resize(75,35);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

Widget::~Widget() {}*/


//2-2
/*
#include <QLabel>
#include <QPushButton>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("Quit",this);
    quit->move(10,10);
    quit->resize(75,35);

    QLabel *label =new QLabel("<font size=20>Hello,World</font>", this);
    label->setGeometry(10,90,75,35);

}

Widget::~Widget() {}*/


//2-3
/*
#include <QLabel>
#include <QPushButton>
#include <QDebug>//추가
#include <QApplication>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("&Quit",this);
    quit->resize(75,35);

    QLabel *label =new QLabel("<font size=20>Hello,World</font>", this);
    label->setGeometry(10,90,175,35);

    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));

}

void Widget::slotQuit()
{
    qDebug("slotQuit");
    qApp->quit();
}

Widget::~Widget() {}*/

//2-4
/*
#include <QLabel>
#include <QPushButton>
#include <QDebug>//추가
#include <QApplication>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("&Quit",this);
    quit->resize(75,35);

    QLabel *label =new QLabel("<font size=20>Hello,World</font>", this);
    label->setGeometry(10,90,175,35);

    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));

}

void Widget::slotQuit()
{
    qDebug("slotQuit");
    //qApp->quit();
    emit clicked();
}

Widget::~Widget() {}*/


//2-5 객체찾기
/*
#include <QLabel>
#include <QPushButton>
#include <QDebug>//추가
#include <QApplication>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("&Quit",this);
    quit->resize(75,35);

    QLabel *label =new QLabel("<font size=20>Hello,World</font>", this);
    label->setGeometry(10,90,175,35);
    label ->setObjectName("label1");

    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));

}

void Widget::slotQuit()
{
    // 이름으로 QLabel 객체 찾기
    QLabel* label = findChild<QLabel*>("label1");
        // 클래스 이름 디버깅 출력
        qDebug("%s", qPrintable(label->metaObject()->className()));
        // 텍스트 변경
        label->setText("World!");
}
Widget::~Widget() {}*/

//2-5 수정후
/*
#include <QLabel>
#include <QPushButton>
#include <QDebug>       // 디버그 출력용
#include <QApplication>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Quit 버튼
    QPushButton *quit = new QPushButton("&Quit", this);
    quit->resize(75, 35);

    // 라벨 생성 및 이름 지정
    QLabel *label = new QLabel("<font size=20>Hello,World</font>", this);
    label->setGeometry(10, 90, 175, 35);
    label->setObjectName("label1");

    // 버튼 클릭 시 slotQuit() 호출
    connect(quit, SIGNAL(clicked()), this, SLOT(slotQuit()));
}

void Widget::slotQuit()
{
    // 이름으로 QLabel 객체 찾기
    QLabel* label = findChild<QLabel*>("label1");
    if (label) {
        // 클래스 이름 디버깅 출력
        qDebug("%s", qPrintable(label->metaObject()->className()));
        // 텍스트 변경
        label->setText("World!");
    } else {
        qDebug("Label not found!");
    }
}

Widget::~Widget() {}*/


//3-6 radiobutton
/*
#include "widget.h"
#include <QRadioButton>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(140, 110);

    // 버튼 그룹 생성
    buttonGroup = new QButtonGroup(this);

    for (int i = 0; i < 4; i++) {
        QString str = QString("RadioButton%15").arg(i+1);

        // 라디오 버튼 생성 및 위치 지정
        radioButton[i] = new QRadioButton(str, this);
        radioButton[i]->move(10, 10 + 20 * i);

        // 버튼 그룹에 추가 (함수 이름 주의)
        buttonGroup->addButton(radioButton[i]);
    }
}

Widget::~Widget() {}*/

//3-7
/*
#include "widget.h"
#include <QCheckBox>
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(140, 110);

    // 버튼 그룹 생성 (옵션: 그룹화하여 일괄 제어 가능)
    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false); // CheckBox는 기본적으로 복수 선택 가능

    for (int i = 0; i < 4; i++) {
        QString str = QString("CheckBox%1").arg(i + 1);

        // 체크박스 생성 및 배치
        checkBox[i] = new QCheckBox(str, this);
        checkBox[i]->move(10, 10 + 20 * i);

        // 버튼 그룹에 추가
        buttonGroup->addButton(checkBox[i], i);
    }
}

Widget::~Widget() {}*/

/*
#include "widget.h"
#include <QCheckBox>
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(180, 120);

    buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(false); // 체크박스는 복수 선택 가능

    for (int i = 0; i < 4; ++i) {
        QString text = QString("CheckBox%1").arg(i + 1);
        checkBox[i] = new QCheckBox(text, this);
        checkBox[i]->move(10, 10 + i * 25);
        buttonGroup->addButton(checkBox[i], i);

        // 각 체크박스 클릭 시 슬롯 연결
        connect(checkBox[i], &QCheckBox::clicked, [=]() {
            selectButton(i);  // 해당 ID로 호출
        });
    }
}

Widget::~Widget() {}

void Widget::selectButton(int id)
{
    bool checked = checkBox[id]->isChecked();
    qDebug() << "CheckBox" << id + 1 << (checked ? "checked" : "unchecked");
}*/


//3-15 수정전
/*
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QValidator>

#include "widget.h"

Widget::Widget(QWidget* parent):QWidget(parent)
{
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);

    doubleValidator -> setBottom(10.0);
    doubleValidator -> setTop(100.0);
    doubleValidator -> setDecimals(3);

    QIntValidator* intvalidator = new QIntValidator(this);

    intValidator -> setBottom(13);
    intValidator -> setTop(19);

    QRegularExpression re("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
    QRegularExpressionValidator* redExpValidator = new QRegularExpressionValidator(re,this);

    QLineEdit* lineEditDouble = new QLineEdit(this);
    lineEditDouble -> setValidator(doubleValidator);

    QLineEdit* lineEditInt = new QLineEdit(this);
    lineEditInt -> setValidator(doubleValidator);

    QLineEdit* lineEditRegExp = new QLineEdit(this);
    lineEditRegExp -> setValidator(doubleValidator);

    QFormLayout* QFormLayout = new QFormLayout(this);
    QFormLayout->addRow("&Double",lineEditDouble);
    QFormLayout ->addRow("&int",lineEditInt);
    QFormLayout ->addRow("&Regular Expression",lineEditRegExp);

    setWindowTitle("validator");
}

Widget::~Widget(){}*/

//3-15
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QValidator>
#include <QRegularExpression>

#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent)
{
    // 실수 입력용 Validator (10.0 ~ 100.0, 소수점 3자리까지)
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);
    doubleValidator->setBottom(10.0);
    doubleValidator->setTop(100.0);
    doubleValidator->setDecimals(3);

    // 정수 입력용 Validator (13 ~ 19)
    QIntValidator* intValidator = new QIntValidator(this);
    intValidator->setBottom(13);
    intValidator->setTop(19);

    // 정규표현식 Validator (IP 주소 형태 예: 192.168.0.1)
    QRegularExpression re("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$");
    QRegularExpressionValidator* regExpValidator = new QRegularExpressionValidator(re, this);

    // QLineEdit 설정
    QLineEdit* lineEditDouble = new QLineEdit(this);
    lineEditDouble->setValidator(doubleValidator);

    QLineEdit* lineEditInt = new QLineEdit(this);
    lineEditInt->setValidator(intValidator); // 정수용 Validator 적용

    QLineEdit* lineEditRegExp = new QLineEdit(this);
    lineEditRegExp->setValidator(regExpValidator); // 정규식 Validator 적용

    // 폼 레이아웃 생성
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow("&Double", lineEditDouble);
    formLayout->addRow("&Int", lineEditInt);
    formLayout->addRow("&IP Address", lineEditRegExp);

    setWindowTitle("Validator Example");
}

Widget::~Widget() {}


