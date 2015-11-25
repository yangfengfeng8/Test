#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T20:31:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    home/home.cpp \
    home/alarm_status.cpp \
    home/outlet_status.cpp

HEADERS  += mainwindow.h \
    home/home.h \
    home/alarm_status.h \
    home/outlet_status.h

FORMS    += mainwindow.ui \
    home/home.ui \
    home/alarm_status.ui \
    home/outlet_status.ui
