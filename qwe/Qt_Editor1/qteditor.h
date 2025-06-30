/*
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>

class QAction;

class QtEditor : public QMainWindow
{
    Q_OBJECT
private:
template <typename T>
QAction* makeAction(QString icon,QString text,T shortCut,\
                    QString toolTip,QObject* recv,const char* slot);


public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

public slots:
    template <typename T>
    QAction* makeAction(QString icon,QString text,T shortCut,\
                                 QString toolTip,QObject* recv,const char* slot);
    void newFile();
    fileMenu -> addAction(quitAct);

};


#endif // QTEDITOR_H*/

//QMenuBar
/*
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QAction>
#include <QKeySequence>

#include <QTextEdit>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

public slots:
    void newFile();
    void copy();

private:
    template <typename T>
    QAction *makeAction(QString icon, QString text, T shortCut, \
                        QString toolTip, QObject* recv, const char* slot);
    template <>
    QAction *makeAction(QString icon, QString text, \
                        const char* shortCut, QString toolTip, \
                        QObject* recv, const char* slot);
    template <typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, Functor lambda);
};

#endif // QTEDITOR_H*/


//Toolbar
/*
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

public slots:
    void newFile();
    void copy();
    void paste();
    void quit();

private:
    QTextEdit* textEdit;
};

#endif // QTEDITOR_H*/



//QTool,QStatus 추가
/*
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QKeySequence>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

public slots:
    void newFile();
    void copy();
    void Cut();


private:
    template <typename T>
    QAction* makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, QObject* recv, const char* slot);
    template <>
    QAction* makeAction<const char*>(QString icon, QString text,
                                      const char* shortCut, QString toolTip,
                                      QObject* recv, const char* slot);
    template <typename T, typename Functor>
    QAction* makeAction(QString icon, QString text, T shortCut,
                        QString toolTip, Functor lambda);

private:
    QTextEdit* textEdit; // 중앙 편집기 위젯
};

#endif // QTEDITOR_H*/


//예림님 파일 모범 답안1
/*
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include <QApplication>
#include<QKeySequence>
#include<QToolBar>
#include<QFontComboBox>
#include<QTextEdit>
#include<QDoubleSpinBox>
#include<QFont>
#include<QStatusBar>
#include<QLabel>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private:
    template<typename T>
    QAction *makeAction(QString icon, QString text,T ShortCut,\
                        QString toolTip, QObject* recv,const char* slot);
    template <>
    QAction *makeAction(QString icon, QString text, \
                        const char* shortCut, QString toolTip, \
                        QObject* recv, const char* slot);
    template<typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut,\
                        QString toolTip,Functor lambda);
public slots:
    void newFile();
    void open();
    void save();
    void print();
    void saveas();
};
#endif // QTEDITOR_H
*/

//QTextEdit의 정렬
#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include <QApplication>
#include<QKeySequence>
#include<QToolBar>
#include<QFontComboBox>
#include<QTextEdit>
#include<QDoubleSpinBox>
#include<QFont>
#include<QStatusBar>
#include<QLabel>

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private:
    template<typename T>
    QAction *makeAction(QString icon, QString text,T ShortCut,\
                        QString toolTip, QObject* recv,const char* slot);
    template <>
    QAction *makeAction(QString icon, QString text, \
                        const char* shortCut, QString toolTip, \
                        QObject* recv, const char* slot);
    template<typename T, typename Functor>
    QAction *makeAction(QString icon, QString text, T shortCut,\
                        QString toolTip,Functor lambda);
public slots:
    void newFile();
    void open();
    void save();
    void print();
    void saveas();

    void alignText();//ㅋㅋㅋㅋ

};
#endif // QTEDITOR_H
