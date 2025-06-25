/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

class QLabel;
class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QLabel *m_label;
    QVector<QPushButton*> m_buttons;
    QString m_num1, m_op;
    bool m_isFirst;
    const qint32 WIDTH = 4;
public slots:
    void setNum();
    void setOp();
};
#endif // WIDGET_H*/

//수정1
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QList>

// 버튼 그리드의 가로, 세로 개수 (4x4)
#define WIDTH 4

class Widget : public QWidget
{
    Q_OBJECT

public:
    // 생성자 (부모 위젯 지정 가능)
    Widget(QWidget *parent = nullptr);
    // 소멸자
    ~Widget();

private slots:
    // 숫자 버튼 클릭 시 호출되는 슬롯
    void setNum();
    // 연산자 버튼 클릭 시 호출되는 슬롯
    void setOp();

private:
    QLabel* m_label;                 // 결과 및 현재 입력 숫자 표시용 라벨
    QList<QPushButton*> m_buttons;  // 16개의 버튼을 저장하는 리스트
    QString m_num1;                  // 첫 번째 피연산자 저장용 문자열
    QString m_op;                   // 선택된 연산자 저장용 문자열 ("+", "-", "x", "/")
    bool m_isFirst = true;           // 새 숫자 입력 시 기존 값 덮어쓰기 여부를 관리하는 플래그
};

#endif // WIDGET_H

