#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T00:57:20
#
#-------------------------------------------------

QT       -= gui

TARGET = FiguresLib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

DEFINES += FIGURESLIB_LIBRARY

SOURCES += \
    figure.cpp \
    point.cpp \
    color.cpp \
    square.cpp \
    polygonshape.cpp \
    polygon.cpp \
    rectangle.cpp

HEADERS +=\
        figureslib_global.h \
    point.h \
    color.h \
    square.h \
    figure.h \
    polygonshape.h \
    polygon.h \
    rectangle.h

DESTDIR = ../build

unix {
    target.path = /usr/lib
    INSTALLS += target
}
