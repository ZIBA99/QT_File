/*
#include "widget.h"

#include <QLabel>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel("0",this);
    m_label -> setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    m_label -> setGeometry(10,5,230,40);

    const char ButtonChar[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "x",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    for(int y = 0; y < WIDTH; ++y){
        for(int x = 0; x < WIDTH; ++x){
            m_buttons.append(new QPushButton(ButtonChar[x+y*WIDTH],this));
            m_buttons.at(x+y*WIDTH)->setGeometry(5+60*x,50+60*y,60,60);
        }
    }
    connect(m_buttons.at(0), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(1), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(2), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(4), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(5), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(6), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(8), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(9), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(10), SIGNAL(clicked()),SLOT(setNum()));
    connect(m_buttons.at(12), SIGNAL(clicked()),SLOT(setNum()));

    connect(m_buttons.at(13),&QPushButton::clicked,this,[=](){m_label->setText("0");});

    connect(m_buttons.at(3), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(7), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(11), SIGNAL(clicked()),SLOT(setOp()));
    connect(m_buttons.at(15), SIGNAL(clicked()),SLOT(setOp()));

    connect(m_buttons.at(14), &QPushButton::clicked, this,[this](){
        qreal result = 0;
        m_isFirst = true;
        if(m_op == "+")
            result = m_num1.toDouble() + m_label -> text().toDouble();
        else if(m_op == "-")
            result = m_num1.toDouble() - m_label -> text().toDouble();
        else if(m_op == "x")
            result = m_num1.toDouble() * m_label -> text().toDouble();
        else if(m_op == "/")
            if(m_label -> text().toDouble()){
                result = m_num1.toDouble() / m_label -> text().toDouble();
            }else{
                m_label -> setText("Error: Cannot Divide by Zero");
                return;
            }
        m_label -> setText(QString::number(result));
    });

    setMinimumSize(250.295);
    setMaximumSize(250.295);
    setWindowTitle("Calculator");
}


Widget::~Widget() {
    delete m_label;
    m_buttons.clear();
}

void Widget::setNum(){
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    QString bStr;
    if(button != nullptr)bStr =button -> text();
    if(m_label != nullptr){
        QString IStr = m_label -> text();
        m_label->setText((IStr == "0"|m_isFirst)?bPtr:Istr+bPtr);
        m_isFirst = false;
    }
}
void Widget::setOp(){
    QPushButton *button = dynamic_cast<QPushButton*>(sender());
    if(button != nullptr)m_op=button->text();
    if(m_label != nullptr){
        m_num1 = m_label -> text();
        m_isFirst = true;
    }
}*/

//수정1
#include "widget.h"
#include <QLabel>
#include <QPushButton>

// 위젯 생성자
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 숫자/결과 표시 레이블 설정
    m_label = new QLabel("0", this);
    m_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter); // 오른쪽 정렬
    m_label->setGeometry(10, 5, 230, 40); // 위치 및 크기 설정

    // 버튼 배열 정의 (숫자 및 연산자 포함)
    const QString ButtonChar[16] = {
        "7", "8", "9", "/",   // 0~3
        "4", "5", "6", "x",   // 4~7
        "1", "2", "3", "-",   // 8~11
        "0", "C", "=", "+"    // 12~15
    };

    /*
    switch(m_op.at(0).toLatin1()){
    case '+': result = m_num1.toDouble() + m_label -> text().toDouble(); break;
    case '-': result = m_num1.toDouble() - m_label -> text().toDouble(); break;
    case 'x': result = m_num1.toDouble() * m_label -> text().toDouble(); break;
    case '/':
        if(m_label -> text().toDouble()){
            result = m_num1.toDouble() + m_label -> text().toDouble();
    }

    //슬롯들을 위한 배열
    const char *methods[16] = {
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(setNum()),SLOT(setNum()),SLOT(setOp()),
        SLOT(setNum()),SLOT(),SLOT(),SLOT(setOp())
};*/

    // 4x4 그리드로 버튼 생성 및 위치 지정
    for (int y = 0; y < WIDTH; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int index = x + y * WIDTH;
            QPushButton* btn = new QPushButton(ButtonChar[index], this);
            btn->setGeometry(5 + 60 * x, 50 + 60 * y, 60, 60);
            //if(n != 13 && n != 14)connect(m_buttons.at(n),SIGNAL(clicked()),methods[n]);
            m_buttons.append(btn); // 버튼 리스트에 추가
        }
    }

    // 숫자 버튼(0~9) 클릭 시 setNum() 슬롯과 연결
    const QList<int> numIndices = {0, 1, 2, 4, 5, 6, 8, 9, 10, 12};
    for (int i : numIndices) {
        connect(m_buttons.at(i), SIGNAL(clicked()), this, SLOT(setNum()));
    }

    // C (Clear) 버튼 클릭 시 표시 초기화
    connect(m_buttons.at(13), &QPushButton::clicked, this, [=]() {
        m_label->setText("0");
    });

    // 연산자 버튼 클릭 시 setOp() 슬롯과 연결
    const QList<int> opIndices = {3, 7, 11, 15}; // "/", "x", "-", "+"
    for (int i : opIndices) {
        connect(m_buttons.at(i), SIGNAL(clicked()), this, SLOT(setOp()));
    }

    // = 버튼 클릭 시 계산 수행
    connect(m_buttons.at(14), &QPushButton::clicked, this, [this]() {
        qreal result = 0;
        m_isFirst = true;// 다음 입력은 새 입력으로 간주

        /*    switch(m_op.at(0).toLatin1()){
        case '+': result = m_num1.toDouble() + m_label -> text().toDouble(); break;
        case '-': result = m_num1.toDouble() - m_label -> text().toDouble(); break;
        case 'x': result = m_num1.toDouble() * m_label -> text().toDouble(); break;
        case '/':
        if(m_label -> text().toDouble()){
            result = m_num1.toDouble() + m_label -> text().toDouble();
        }*/

        // 다음 입력은 새 입력으로 간주

        // 연산자에 따라 계산 수행
        if (m_op == "+")
            result = m_num1.toDouble() + m_label->text().toDouble();
        else if (m_op == "-")
            result = m_num1.toDouble() - m_label->text().toDouble();
        else if (m_op == "x")
            result = m_num1.toDouble() * m_label->text().toDouble();
        else if (m_op == "/") {
            if (m_label->text().toDouble()) { // 0으로 나누지 않도록 체크
                result = m_num1.toDouble() / m_label->text().toDouble();
            } else {
                m_label->setText("Error: Cannot Divide by Zero");
                return;
            }
        }

        // 결과를 문자열로 변환하여 표시
        m_label->setText(QString::number(result));
    });

    // 창 크기 설정
    setMinimumSize(250, 295);
    setMaximumSize(250, 295);
    setWindowTitle("Calculator"); // 창 제목 설정
}

// 소멸자: 레이블 및 버튼 메모리 해제
Widget::~Widget() {
    delete m_label;
    qDeleteAll(m_buttons); // 버튼 객체 제거
    m_buttons.clear();     // 리스트 비우기
}

// 숫자 버튼 클릭 시 호출되는 슬롯
void Widget::setNum() {
    QPushButton *button = dynamic_cast<QPushButton*>(sender()); // 누른 버튼 포인터 가져오기
    QString bStr;
    if (button != nullptr) bStr = button->text(); // 버튼 텍스트 추출

    if (m_label != nullptr) {
        QString IStr = m_label->text(); // 현재 입력된 숫자

#if 1 \
    // 기존 입력이 0이거나 연산 후 첫 입력이면 새로 덮어씀
        m_label->setText((IStr == "0" || m_isFirst) ? bStr : IStr + bStr);
#else \
    // 이 방식은 숫자를 10진법으로 누적하여 처리 (예시용, 주석 처리됨)
        m_label->setText(QString::number(IStr.toDouble() * 10 + bStr.toDouble()));
#endif
        m_isFirst = false; // 연산 직후가 아님을 표시
    }
}

// 연산자 버튼 클릭 시 호출되는 슬롯
void Widget::setOp() {
    QPushButton *button = dynamic_cast<QPushButton*>(sender()); // 누른 버튼 포인터 가져오기
    if (button != nullptr) m_op = button->text(); // 연산자 저장

    if (m_label != nullptr) {
        m_num1 = m_label->text(); // 현재 입력값을 첫 번째 피연산자로 저장
        m_isFirst = true; // 다음 숫자 입력 시 덮어쓰도록 설정
    }
}

