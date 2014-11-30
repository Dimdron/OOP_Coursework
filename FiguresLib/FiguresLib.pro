#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T00:57:20
#
#-------------------------------------------------

QT       -= gui

TARGET = FiguresLib
TEMPLATE = lib

DEFINES += FIGURESLIB_LIBRARY

SOURCES += \
    figure.cpp \
    point.cpp \
    color.cpp \
    square.cpp

HEADERS +=\
        figureslib_global.h \
    figure.h \
    point.h \
    color.h \
    square.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
