QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 서버와 클라이언트를 동시에 실행하는 단일 애플리케이션
SOURCES += \
    main.cpp \
    widget.cpp \
    widget_c.cpp

HEADERS += \
    widget.h \
    widget_c.h

# main_c.cpp는 제외
# SOURCES += main_c.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
