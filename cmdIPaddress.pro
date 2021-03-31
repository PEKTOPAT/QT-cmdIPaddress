#-------------------------------------------------
#
# Project created by QtCreator 2021-03-01T09:20:32
#
#-------------------------------------------------

QT       += core gui
QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cmdIPaddress
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    networkinterfaces.cpp

HEADERS  += mainwindow.h \
    networkinterfaces.h

FORMS    += mainwindow.ui

CONFIG += console

LIBS += -lIphlpapi

