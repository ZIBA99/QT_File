#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDoubleSpinBox>
#include<QFont>
#include<QStatusBar>
#include<QLabel>
#include <QTextEdit>
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include <QApplication>
#include<QKeySequence>
#include<QToolBar>
#include<QFontComboBox>
#include<QDockWidget>

class QLabel;
class QMdiArea;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QMdiArea *midArea;//5장

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTextEdit *textedit;
    QTextEdit *textedit_dock;
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
    QTextEdit *newFile();//5장
    //void newFile();
    void open();
    void save();
    void print();
    void saveas();
};
#endif // MAINWINDOW_H
