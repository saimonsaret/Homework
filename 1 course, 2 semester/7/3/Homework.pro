#-------------------------------------------------
#
# Project created by QtCreator 2014-05-02T22:50:54
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
    gameprocess.cpp \
    game.cpp

HEADERS  += mainwindow.h \
    game.h \
    gameprocess.h \
    testgame.h

FORMS    += mainwindow.ui
