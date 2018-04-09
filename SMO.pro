#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11T16:49:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SMO
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    buffer.cpp \
    request.cpp \
    model.cpp \
    dispatchmanager.cpp \
    source.cpp \
    dev.cpp \
    dispatchservice.cpp \
    statistics.cpp \
    event.cpp \
    formstepmode.cpp \
    formautomode.cpp

HEADERS += \
        mainwindow.h \
    buffer.h \
    model.h \
    request.h \
    dispatchmanager.h \
    source.h \
    dev.h \
    dispatchservice.h \
    statistics.h \
    event.h \
    formstepmode.h \
    formautomode.h

FORMS += \
        mainwindow.ui \
    formstepmode.ui \
    formautomode.ui

QMAKE_CXXFLAGS += -std=c++11
