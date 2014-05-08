#-------------------------------------------------
#
# Project created by QtCreator 2014-03-12T18:24:56
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    testcalculator.h

FORMS    += mainwindow.ui
