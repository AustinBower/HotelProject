#-------------------------------------------------
#
# Project created by QtCreator 2015-04-21T13:00:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    alterroomform.cpp \
    loginscreen.cpp \
    logincreds.cpp \
    checkinsdialog.cpp \
    nightcharts.cpp \
    reports.cpp \
    statsdialog.cpp \
    viewreportdialog.cpp

HEADERS  += mainwindow.h \
    room.h \
    alterroomform.h \
    loginscreen.h \
    logincreds.h \
    checkinsdialog.h \
    nightcharts.h \
    reports.h \
    statsdialog.h \
    viewreportdialog.h

FORMS    += mainwindow.ui \
    alterroomform.ui \
    loginscreen.ui \
    checkinsdialog.ui \
    reports.ui \
    statsdialog.ui \
    viewreportdialog.ui

RESOURCES += \
    resources.qrc
