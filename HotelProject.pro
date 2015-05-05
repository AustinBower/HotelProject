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
    alterroomform.cpp

HEADERS  += mainwindow.h \
    room.h \
    alterroomform.h

FORMS    += mainwindow.ui \
    alterroomform.ui

RESOURCES += \
    resources.qrc
