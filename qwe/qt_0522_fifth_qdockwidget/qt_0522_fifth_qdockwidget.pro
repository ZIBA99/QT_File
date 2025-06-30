QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qteditor.qrc

DISTFILES += \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/center.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/copy.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/cut.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/justify.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/left.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/new.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/open.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/paste.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/print.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/quit.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/redo.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/right.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/save.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/saveas.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/undo.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/zoomin.png \
    build/Desktop_Qt_6_9_0_MSVC2022_64bit-Debug/zoomout.png
