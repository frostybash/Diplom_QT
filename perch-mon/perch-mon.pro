#-------------------------------------------------
#
# Project created by QtCreator 2019-12-16T17:46:11
#
#-------------------------------------------------

QT       += core gui network widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = perch-mon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chartclass.cpp

HEADERS  += mainwindow.h \
    chartclass.h

FORMS    += mainwindow.ui
