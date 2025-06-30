/*
#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // QTextEdit 위젯 생성
    QTextEdit* textEdit = new QTextEdit(this);

    // 중앙 위젯으로 설정하여 메인 영역에 표시
    setCentralWidget(textEdit);

    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QAction *newAct = new QAction(QIcon("Make New File.png"),"&New",this);
    newAct -> setShortcut(tr("Ctrl+N"));
    newAct -> setStatusTip(tr("make new file"));
    connect(newAct, SIGNAL(triggered()),SLOT(newFile()));

    QMenu* fileMenu = menubar -> addMenu("&File");
    fileMenu -> addAction(newAct);
    QMenu* fileMenu1 = menubar -> addMenu("&Edit");
    QMenu* fileMenu2 = menubar -> addMenu("&View");
    QMenu* fileMenu3 = menubar -> addMenu("&Build");

    //QMenu* fileMenu = menubar -> addMenu("&File");
    //QMenu* fileMenu1 = menubar -> addMenu("&양자");
    //QMenu* fileMenu2 = menubar -> addMenu("&허수");
    void QtEditor::newFile()
    {
        qDebug("Make New File");
    }
}

QtEditor::~QtEditor() {}*/

//구현 예제
/*
#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug> // qDebug 사용 시 필수
#include <QApplication>
#include <OKeySequence>

    QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // QTextEdit 위젯 생성
    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit); // 중앙 위젯 지정

    // 메뉴바 생성 및 등록
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // 'New' 액션 생성
    QAction *newAct = new QAction(QIcon("Make New File.png"), "&New", this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("Make new file"));

    // 슬롯 연결
    connect(newAct, &QAction::triggered, this, &QtEditor::newFile);

    // 메뉴 생성
    QMenu* fileMenu = menubar->addMenu("&File");
    fileMenu->addAction(newAct);
    menubar->addMenu("&Edit");
    menubar->addMenu("&View");
    menubar->addMenu("&Build");
}


// 슬롯 함수 정의
void QtEditor::newFile()
{
    qDebug("Make New File"); // 콘솔에 출력
}

QtEditor::~QtEditor() {}*/


// 구현 실습 MenuBar
/*
#include "qteditor.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QDebug>
#include <QIcon>

#include<QStatusBar>

// 생성자
QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // 중앙 편집기 설정
    QTextEdit* textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 메뉴 바 생성
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File 메뉴 생성
    QMenu* fileMenu = menubar->addMenu(tr("&File"));
    QMenu* fileMenu1 = menubar->addMenu(tr("&Edit"));

    // 템플릿 함수 사용한 액션 생성
    QAction* newAct = makeAction("new.png", tr("&New"), QKeySequence("Ctrl+N"),
                                 tr("Create a new file"), this, SLOT(newFile()));
    QAction* quitAct = makeAction("quit.png", tr("&Quit"), "Ctrl+Q",
                                  tr("Exit the program"), qApp, SLOT(quit()));
    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // Edit 메뉴 액션들 (textEdit의 기본 슬롯에 연결)
    QAction* cutAct = makeAction("cut.png", tr("Cu&t"), QKeySequence("Ctrl+X"),
                                 tr("Cut selected text"), textEdit, SLOT(cut()));
    QAction* copyAct = makeAction("copy.png", tr("&Copy"), QKeySequence("Ctrl+C"),
                                  tr("Copy selected text"), textEdit, SLOT(copy()));
    QAction* pasteAct = makeAction("paste.png", tr("&Paste"), QKeySequence("Ctrl+V"),
                                   tr("Paste text from clipboard"), textEdit, SLOT(paste()));

    fileMenu1->addAction(cutAct);
    fileMenu1->addSeparator();
    fileMenu1->addAction(copyAct);
    //fileMenu1->addSeparator(); 줄
    fileMenu1->addAction(pasteAct);


}

// 슬롯 함수 정의
void QtEditor::newFile()
{
    qDebug("Make New File");
}

void QtEditor::copy()
{
    qDebug("copy");
}

// 템플릿 함수 정의 (기본 버전)
template <typename T>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, QObject* recv, const char* slot)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortCut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot); // 구형 방식
    return act;
}

// 템플릿 특수화 (const char*용)
template <>
QAction* QtEditor::makeAction<const char*>(QString icon, QString text,
                                            const char* shortCut, QString toolTip,
                                            QObject* recv, const char* slot)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(QString::fromLatin1(shortCut)));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 람다용 템플릿
template <typename T, typename Functor>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, Functor lambda)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortCut));
    act->setStatusTip(toolTip);
    connect(act, &QAction::triggered, lambda);
    return act;
}

// 소멸자
QtEditor::~QtEditor() {}*/

/*
#include "qteditor.h"
#include <QToolBar>
#include <QMenuBar>
#include <QApplication>
#include <QDebug>
#include <QIcon>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // 텍스트 편집기 설정
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 툴바 생성
    QToolBar* toolBar = addToolBar(tr("Main Toolbar"));

    // 액션 생성 및 연결
    QAction* newAct = new QAction(QIcon(":/icons/new.png"), tr("New"), this);
    connect(newAct, &QAction::triggered, this, &QtEditor::newFile);

    QAction* copyAct = new QAction(QIcon(":/icons/copy.png"), tr("Copy"), this);
    connect(copyAct, &QAction::triggered, this, &QtEditor::copy);

    QAction* pasteAct = new QAction(QIcon(":/icons/paste.png"), tr("Paste"), this);
    connect(pasteAct, &QAction::triggered, this, &QtEditor::paste);

    QAction* quitAct = new QAction(QIcon(":/icons/quit.png"), tr("Quit"), this);
    connect(quitAct, &QAction::triggered, this, &QtEditor::quit);

    // 툴바에 액션 추가
    toolBar->addAction(newAct);
    toolBar->addAction(copyAct);
    toolBar->addAction(pasteAct);
    toolBar->addSeparator();
    toolBar->addAction(quitAct);
}

QtEditor::~QtEditor() {}

void QtEditor::newFile()
{
    textEdit->clear();
    qDebug() << "새 파일 생성";
}

void QtEditor::copy()
{
    textEdit->copy();
    qDebug() << "복사됨";
}

void QtEditor::paste()
{
    textEdit->paste();
    qDebug() << "붙여넣기";
}

void QtEditor::quit()
{
    qApp->quit();
}*/

//Toobar,Statusbar 추가
/*
#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QToolBar>
#include <QStatusBar>

// 생성자
QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // 중앙 편집기 설정
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 메뉴 바 생성
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File 메뉴 생성
    QMenu* fileMenu = menubar->addMenu(tr("&File"));
    QMenu* editMenu = menubar->addMenu(tr("&Edit"));

    // 템플릿 함수 사용한 액션 생성
    QAction* newAct = makeAction("new.png", tr("&New"), QKeySequence("Ctrl+N"),
                                 tr("Create a new file"), this, SLOT(newFile()));
    QAction* quitAct = makeAction("quit.png", tr("&Quit"), "Ctrl+Q",
                                  tr("Exit the program"), qApp, SLOT(quit()));

    fileMenu->addAction(newAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // Edit 메뉴 액션들 (textEdit의 기본 슬롯에 연결)
    QAction* cutAct = makeAction("cut.png", tr("Cu&t"), QKeySequence("Ctrl+X"),
                                 tr("Cut selected text"), textEdit, SLOT(cut()));
    QAction* copyAct = makeAction("copy.png", tr("&Copy"), QKeySequence("Ctrl+C"),
                                  tr("Copy selected text"), textEdit, SLOT(copy()));
    QAction* pasteAct = makeAction("paste.png", tr("&Paste"), QKeySequence("Ctrl+V"),
                                   tr("Paste text from clipboard"), textEdit, SLOT(paste()));

    editMenu->addAction(cutAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addSeparator();
    editMenu->addAction(pasteAct);

    // 툴바 설정

    QToolBar* toolbar = addToolBar(tr("Main Toolbar"));

    toolbar->setIconSize(QSize(48, 48)); // 아이콘 크기 키우기
    toolbar->setStyleSheet("QToolBar { padding: 8px; }"); // 여백 추가
    toolbar->addAction(newAct); // New 액션 툴바에 추가
    toolbar->addAction(cutAct); // Cut 액션 툴바에 추가
    toolbar->addAction(copyAct); // Copy 액션 툴바에 추가
    toolbar->addAction(pasteAct); // Paste 액션 툴바에 추가

    // 상태 바 설정
    statusBar()->showMessage(tr("Ready"));

    // 툴바와 상태 바 관련 연결
    connect(cutAct, &QAction::triggered, this, [this] {
        statusBar()->showMessage(tr("Cut operation executed"));
    });

    connect(copyAct, &QAction::triggered, this, [this] {
        statusBar()->showMessage(tr("Copy operation executed"));
    });

    connect(pasteAct, &QAction::triggered, this, [this] {
        statusBar()->showMessage(tr("Paste operation executed"));
    });
}

// 슬롯 함수 정의
void QtEditor::newFile()
{
    qDebug("Make New File");
}

void QtEditor::copy()
{
    //qDebug("copy");
    qDebug() << "copy";
}
void QtEditor::Cut()
{
    //qDebug("Cut");
    qDebug() << "Cut";
}


// 템플릿 함수 정의 (기본 버전)
template <typename T>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, QObject* recv, const char* slot)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortCut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot); // 구형 방식
    return act;
}

// 템플릿 특수화 (const char*용)
template <>
QAction* QtEditor::makeAction<const char*>(QString icon, QString text,
                                            const char* shortCut, QString toolTip,
                                            QObject* recv, const char* slot)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(QString::fromLatin1(shortCut)));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 람다용 템플릿
template <typename T, typename Functor>
QAction* QtEditor::makeAction(QString icon, QString text, T shortCut,
                              QString toolTip, Functor lambda)
{
    QAction* act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortCut));
    act->setStatusTip(toolTip);
    connect(act, &QAction::triggered, lambda);
    return act;
}

// 소멸자
QtEditor::~QtEditor() {}*/

//예림님 파일 모범 답안1
/*
#include "qteditor.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QFont>
#include <QStatusBar>
#include <QLabel>

// 생성자
QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // 중앙 텍스트 에디터
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    // 메뉴바 설정
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File 메뉴 및 액션
    QAction *newAct = makeAction("new.png", tr("&New"), QKeySequence::New, tr("Create new file"), this, SLOT(newFile()));
    QAction *quitAct = makeAction("quit.png", tr("&Quit"), "Ctrl+Q", tr("Exit program"), qApp, SLOT(quit()));
    QAction *openAct = makeAction("open.png", tr("&Open"), QKeySequence::Open, tr("Open file"), this, SLOT(open()));
    QAction *saveAct = makeAction("save.png", tr("&Save"), QKeySequence::Save, tr("Save file"), this, SLOT(save()));
    QAction *printAct = makeAction("print.png", tr("&Print"), QKeySequence::Print, tr("Print"), this, SLOT(print()));
    QAction *saveasAct = makeAction("saveas.png", tr("Save &As"), QKeySequence::SaveAs, tr("Save as..."), this, SLOT(saveas()));

    QMenu *fileMenu = menubar->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // Edit 메뉴 및 람다 연결
    QAction *undoAct = makeAction("undo.png", tr("&Undo"), QKeySequence::Undo, tr("Undo"), [=]() { textedit->undo(); });
    QAction *redoAct = makeAction("redo.png", tr("&Redo"), QKeySequence::Redo, tr("Redo"), [=]() { textedit->redo(); });
    QAction *copyAct = makeAction("copy.png", tr("&Copy"), QKeySequence::Copy, tr("Copy"), [=]() { textedit->copy(); });
    QAction *cutAct = makeAction("cut.png", tr("Cu&t"), QKeySequence::Cut, tr("Cut"), [=]() { textedit->cut(); });
    QAction *pasteAct = makeAction("paste.png", tr("&Paste"), QKeySequence::Paste, tr("Paste"), [=]() { textedit->paste(); });
    QAction *zoomInAct = makeAction("zoomin.png", tr("Zoom &In"), QKeySequence::ZoomIn, tr("Zoom In"), [=]() { textedit->zoomIn(); });
    QAction *zoomOutAct = makeAction("zoomout.png", tr("Zoom &Out"), QKeySequence::ZoomOut, tr("Zoom Out"), [=]() { textedit->zoomOut(); });

    QMenu *editMenu = menubar->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    // File 툴바
    QToolBar *fileToolBar = addToolBar(tr("File Toolbar"));
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->setIconSize(QSize(32, 32)); // 툴바 아이콘 크기 설정
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(quitAct);

    // Format 툴바
    addToolBarBreak(); // 툴바 구분선
    QToolBar *formatToolbar = addToolBar(tr("Format Toolbar"));
    formatToolbar->setIconSize(QSize(32, 32));
    QFontComboBox *fontComboBox = new QFontComboBox(this);
    QDoubleSpinBox *fontSizeSpinBox = new QDoubleSpinBox(this);
    fontSizeSpinBox->setRange(8, 72);
    fontSizeSpinBox->setValue(12);

    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(fontSizeSpinBox);

    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), textedit, SLOT(setCurrentFont(QFont)));
    connect(fontSizeSpinBox, SIGNAL(valueChanged(double)), textedit, SLOT(setFontPointSize(qreal)));

    // 상태바
    QStatusBar *statusBarWidget = statusBar();
    QLabel *statusLabel = new QLabel(tr("Ready"), this);
    statusBarWidget->addPermanentWidget(statusLabel);
    statusBarWidget->showMessage("Qt Editor 시작됨", 2000);

    // 툴바 숨기기 메뉴
    QMenu *windowMenu = menubar->addMenu(tr("&Window"));
    QMenu *toolbarMenu = windowMenu->addMenu(tr("&Toolbars"));
    toolbarMenu->addAction(fileToolBar->toggleViewAction());
    toolbarMenu->addAction(formatToolbar->toggleViewAction());
}

// 슬롯 함수 정의
void QtEditor::newFile() { qDebug("New File Created"); }
void QtEditor::open() { qDebug("Open File Dialog"); }
void QtEditor::save() { qDebug("Save File"); }
void QtEditor::print() { qDebug("Print File"); }
void QtEditor::saveas() { qDebug("Save File As"); }

// 템플릿 기본 함수
template<typename T>
QAction* QtEditor::makeAction(QString icon, QString text, T shortcut, QString toolTip, QObject* recv, const char* slot)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortcut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 템플릿 특수화: const char*
template<>
QAction* QtEditor::makeAction<const char*>(QString icon, QString text, const char* shortcut, QString toolTip, QObject* recv, const char* slot)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(QString::fromLatin1(shortcut)));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 람다용 템플릿 함수
template<typename T, typename Functor>
QAction* QtEditor::makeAction(QString icon, QString text, T shortcut, QString toolTip, Functor lambda)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortcut));
    act->setStatusTip(toolTip);
    connect(act, &QAction::triggered, lambda);
    return act;
}

// 소멸자
QtEditor::~QtEditor() {}*/


//QTextEdit의 정렬
#include "qteditor.h"

#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QFont>
#include <QStatusBar>
#include <QLabel>

// 생성자
QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)
{
    // 중앙 텍스트 에디터
    QTextEdit *textedit = new QTextEdit(this);
    setCentralWidget(textedit);

    // 메뉴바 설정
    QMenuBar *menubar = new QMenuBar(this);
    setMenuBar(menubar);

    // File 메뉴 및 액션
    QAction *newAct = makeAction("new.png", tr("&New"), QKeySequence::New, tr("Create new file"), this, SLOT(newFile()));
    QAction *quitAct = makeAction("quit.png", tr("&Quit"), "Ctrl+Q", tr("Exit program"), qApp, SLOT(quit()));
    QAction *openAct = makeAction("open.png", tr("&Open"), QKeySequence::Open, tr("Open file"), this, SLOT(open()));
    QAction *saveAct = makeAction("save.png", tr("&Save"), QKeySequence::Save, tr("Save file"), this, SLOT(save()));
    QAction *printAct = makeAction("print.png", tr("&Print"), QKeySequence::Print, tr("Print"), this, SLOT(print()));
    QAction *saveasAct = makeAction("saveas.png", tr("Save &As"), QKeySequence::SaveAs, tr("Save as..."), this, SLOT(saveas()));

    QMenu *fileMenu = menubar->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    // Edit 메뉴 및 람다 연결
    QAction *undoAct = makeAction("undo.png", tr("&Undo"), QKeySequence::Undo, tr("Undo"), [=]() { textedit->undo(); });
    QAction *redoAct = makeAction("redo.png", tr("&Redo"), QKeySequence::Redo, tr("Redo"), [=]() { textedit->redo(); });
    QAction *copyAct = makeAction("copy.png", tr("&Copy"), QKeySequence::Copy, tr("Copy"), [=]() { textedit->copy(); });
    QAction *cutAct = makeAction("cut.png", tr("Cu&t"), QKeySequence::Cut, tr("Cut"), [=]() { textedit->cut(); });
    QAction *pasteAct = makeAction("paste.png", tr("&Paste"), QKeySequence::Paste, tr("Paste"), [=]() { textedit->paste(); });
    QAction *zoomInAct = makeAction("zoomin.png", tr("Zoom &In"), QKeySequence::ZoomIn, tr("Zoom In"), [=]() { textedit->zoomIn(); });
    QAction *zoomOutAct = makeAction("zoomout.png", tr("Zoom &Out"), QKeySequence::ZoomOut, tr("Zoom Out"), [=]() { textedit->zoomOut(); });

    QMenu *editMenu = menubar->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);

    // File 툴바
    QToolBar *fileToolBar = addToolBar(tr("File Toolbar"));
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->setIconSize(QSize(32, 32)); // 툴바 아이콘 크기 설정
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(quitAct);

    // Format 툴바
    addToolBarBreak(); // 툴바 구분선
    QToolBar *formatToolbar = addToolBar(tr("Format Toolbar"));
    formatToolbar->setIconSize(QSize(32, 32));
    QFontComboBox *fontComboBox = new QFontComboBox(this);
    QDoubleSpinBox *fontSizeSpinBox = new QDoubleSpinBox(this);
    fontSizeSpinBox->setRange(8, 72);
    fontSizeSpinBox->setValue(12);

    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(fontSizeSpinBox);

    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), textedit, SLOT(setCurrentFont(QFont)));
    connect(fontSizeSpinBox, SIGNAL(valueChanged(double)), textedit, SLOT(setFontPointSize(qreal)));

    // 상태바
    QStatusBar *statusBarWidget = statusBar();
    QLabel *statusLabel = new QLabel(tr("Ready"), this);
    statusBarWidget->addPermanentWidget(statusLabel);
    statusBarWidget->showMessage("Qt Editor 시작됨", 2000);

    // 툴바 숨기기 메뉴
    QMenu *windowMenu = menubar->addMenu(tr("&Window"));
    QMenu *toolbarMenu = windowMenu->addMenu(tr("&Toolbars"));
    toolbarMenu->addAction(fileToolBar->toggleViewAction());
    toolbarMenu->addAction(formatToolbar->toggleViewAction());
}

// 슬롯 함수 정의
void QtEditor::newFile() { qDebug("New File Created"); }
void QtEditor::open() { qDebug("Open File Dialog"); }
void QtEditor::save() { qDebug("Save File"); }
void QtEditor::print() { qDebug("Print File"); }
void QtEditor::saveas() { qDebug("Save File As"); }

// 템플릿 기본 함수
template<typename T>
QAction* QtEditor::makeAction(QString icon, QString text, T shortcut, QString toolTip, QObject* recv, const char* slot)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortcut));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 템플릿 특수화: const char*
template<>
QAction* QtEditor::makeAction<const char*>(QString icon, QString text, const char* shortcut, QString toolTip, QObject* recv, const char* slot)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(QString::fromLatin1(shortcut)));
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()), recv, slot);
    return act;
}

// 람다용 템플릿 함수
template<typename T, typename Functor>
QAction* QtEditor::makeAction(QString icon, QString text, T shortcut, QString toolTip, Functor lambda)
{
    QAction *act = new QAction(QIcon(icon), text, this);
    act->setShortcut(QKeySequence(shortcut));
    act->setStatusTip(toolTip);
    connect(act, &QAction::triggered, lambda);
    return act;
}

// 소멸자
QtEditor::~QtEditor() {}
