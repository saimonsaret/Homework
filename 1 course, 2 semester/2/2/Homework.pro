TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    printer.cpp \
    direction.cpp

HEADERS += \
    printer.h \
    consolePrinter.h \
    filePrinter.h \
    direction.h \
    point.h \
    matrix.h

