#-------------------------------------------------
#
# Project created by QtCreator 2016-03-24T14:19:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PBAndPA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    PA/padevicelist.cpp \
    PA/paPortName.cpp \
    PA/PAManagerTab/pamanagertab.cpp \
    PA/PAManagerTab/pacontrol.cpp \
    PA/pabase.cpp

HEADERS  += mainwindow.h \
    PA/padevicelist.h \
    PA/paPortName.h \
    PA/PAManagerTab/pamanagertab.h \
    PA/PAManagerTab/pacontrol.h \
    paspinboxdelegate.h \
    PA/pabase.h

FORMS    += mainwindow.ui \
    PA/padevicelist.ui \
    PA/paPortName.ui \
    PA/PAManagerTab/pamanagertab.ui \
    PA/PAManagerTab/pacontrol.ui

RESOURCES += \
    image.qrc
