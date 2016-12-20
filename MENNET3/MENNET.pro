#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T14:15:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MENNET
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialoginput.cpp \
    widget.cpp

HEADERS  += mainwindow.h \
    dialoginput.h \
    widget.h \
    main.h

FORMS    += mainwindow.ui \
    dialoginput.ui \
    widget.ui
