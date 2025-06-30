//2-1,2-2
/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H*/


//2-3,2-4
/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals: //2-4
    void clicked();

public slots:
    void slotQuit();
};
#endif // WIDGET_H*/

//3-6
/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QRadioButton *radioButton[4];
    QButtonGroup *buttonGroup;
};

#endif // WIDGET_H*/

//3-7
/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>

// 불필요한 중복 포함 제거
class QCheckBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QCheckBox* checkBox[4];        // 4개의 체크박스
    QButtonGroup *buttonGroup;     // 그룹으로 관리

public slots:
    void selectButton(int id);     // ID로 선택된 버튼 처리
};

#endif // WIDGET_H
*/

/*
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QButtonGroup>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QCheckBox *checkBox[4];
    QButtonGroup *buttonGroup;
};

#endif // WIDGET_H
*/

//3-15
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H

