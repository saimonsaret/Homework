#-------------------------------------------------
#
# Project created by QtCreator 2014-05-21T23:23:42
#
#-------------------------------------------------

QT       += core gui
QT       += core xml widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    formcreator.cpp \
    xmlsimplecontenthandler.cpp

HEADERS  += mainwindow.h \
    xmlsimplecontenthandler.h \
    widgettree.h \
    formcreator.h

FORMS    += mainwindow.ui
