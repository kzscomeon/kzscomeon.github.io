#-------------------------------------------------
#
# Project created by QtCreator 2022-11-11T21:22:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo3
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    note.cpp \
    label.cpp

HEADERS  += widget.h \
    label.h

FORMS    += widget.ui
