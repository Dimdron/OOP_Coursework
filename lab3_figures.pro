#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T23:05:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3_figures
CONFIG   += c++11

TEMPLATE = app

INCLUDEPATH += FiguresLib

SOURCES += main.cpp\
        mainwindow.cpp \
    renderer.cpp

HEADERS  += mainwindow.h \
    renderer.h

FORMS    += mainwindow.ui

LIBS += -L$$PWD/build -lFiguresLib
