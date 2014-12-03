#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T17:22:43
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp

HEADERS  += mainwindow.h \
    computer.h \
    test.h

FORMS    += mainwindow.ui
