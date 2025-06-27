# ----------------------------------------------------
# Project created by QtCreator 2023-10-27T10:00:00
# ----------------------------------------------------

QT       += core gui

# [필수] TCP/IP 통신을 위해 network 모듈을 추가합니다.
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated in Qt 5.15.0.
# It's good practice to enable this so you can later upgrade your code.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to fail if you use deprecated APIs in versions older
# than a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    clientwidget.cpp \
    main.cpp \
    serverwidget.cpp \
    clientwidget.cpp  # [추가] 클라이언트 소스 파일

HEADERS += \
    clientwidget.h \
    serverwidget.h \
    clientwidget.h    # [추가] 클라이언트 헤더 파일

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
