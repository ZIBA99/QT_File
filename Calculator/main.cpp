/*
#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QString>

class Calculator{
public:
    Calculator(double num1 = 0, char op = ' ', double num2 = 0)
        :num1(num1), op(op), num2(num2){}
    void input(){std::cin>>num1>>op>>num2;}
    double doCalsulate(){
        double result;
        switch(op){
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': result = num1 / (double)num2; break;
        };
        return result;
    }
private:
    double num1, num2;
    char op;
};

int main(){
    Calculator c;
    c.input();
    std::cout << c.doCalsulate() << std::endl;

    const QString ButtonChar[16] = {
        "7", "8", "9", "/",
        "4", "5", "6", "x",
        "1", "2", "3", "-",
        "0", "C", "=", "+"
    };

    label = new QLabel("0", this);
    label->setGeometry(10, 5, 230, 40);
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QPushButton *buttons[16];
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int idx = x + y * WIDTH;
            buttons[idx] = new QPushButton(ButtonChar[idx], this);
            buttons[idx]->setGeometry(5 + 60 * x, 50 + 60 * y, 60, 60);
        }
    }

    return 0;
}*/

/*
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QWidget>

#define WIDTH 4

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        const QString ButtonChar[16] = {
            "7", "8", "9", "/",
            "4", "5", "6", "x",
            "1", "2", "3", "-",
            "0", "C", "=", "+"
        };

        QLabel *label = new QLabel("0", this);  // 선언 추가
        label->setGeometry(10, 5, 230, 40);
        label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

        QPushButton *buttons[16];
        for (int y = 0; y < WIDTH; y++) {
            for (int x = 0; x < WIDTH; x++) {
                int idx = x + y * WIDTH;
                buttons[idx] = new QPushButton(ButtonChar[idx], this);
                buttons[idx]->setGeometry(5 + 60 * x, 50 + 60 * y, 60, 60);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.setFixedSize(260, 320);
    widget.show();
    return app.exec();
}*/

//수정1
#include <QApplication>  // QApplication 클래스 포함
#include "widget.h"      // 사용자 정의 위젯 클래스 포함

int main(int argc, char *argv[])
{
    // QApplication 객체 생성: Qt 애플리케이션을 실행하는 데 필수
    QApplication app(argc, argv);

    // 사용자 정의 위젯 객체 생성
    Widget w;
    // 위젯을 화면에 표시
    w.show();

    // 이벤트 루프 실행 (프로그램이 종료될 때까지 계속 실행)
    return app.exec();
}
