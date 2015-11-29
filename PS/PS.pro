#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T10:41:43
#
#-------------------------------------------------

QT       += core gui
QT       += network

LIBS     += -L "D:\qt5.5\5.5\mingw492_32\lib" -lqwt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog/rename.cpp \
    dialog/changedevice.cpp \
    dialog/adduser.cpp \
    dialog/loginin.cpp \
    logic/logicaction.cpp \
    dialog/all_btn.cpp \
    dialog/add_device.cpp \
    curve/curve_widget.cpp \
    curve/curve.cpp \
    home/alarm_status.cpp \
    home/home.cpp \
    Device_Manager/control.cpp \
    Device_Manager/loadmanagement.cpp \
    Device_Manager/outlet_configuration.cpp \
    Device_Manager/outlet_configure_child.cpp \
    Device_Manager/scheduling.cpp \
    Event/log_event.cpp \
    Device_Manager/control_confirmation.cpp \
    base.cpp \
    Event/log_widget.cpp

HEADERS  += mainwindow.h \
    add_device.h \
    dialog/rename.h \
    dialog/changedevice.h \
    base.h \
    dialog/adduser.h \
    dialog/loginin.h \
    logic/logicaction.h \
    dialog/all_btn.h \
    dialog/add_device.h \
    curve/curve_widget.h \
    curve/curve.h \
    home/alarm_status.h \
    home/home.h \
    Device_Manager/control.h \
    Device_Manager/loadmanagement.h \
    Device_Manager/outlet_configuration.h \
    Device_Manager/outlet_configure_child.h \
    Device_Manager/scheduling.h \
    Event/log_event.h \
    Device_Manager/control_confirmation.h \
    Event/log_widget.h

FORMS    += mainwindow.ui \
    home/home.ui \
    home/alarm_status.ui \
    Device_Manager/control.ui \
    Device_Manager/loadmanagement.ui \
    Device_Manager/outlet_configuration.ui \
    Device_Manager/outlet_configuration_child.ui \
    Device_Manager/scheduling.ui \
    Event/log_event.ui \
    Device_Manager/control_confirmation.ui \
    Event/log_widget.ui

RESOURCES += \
    images.qrc
