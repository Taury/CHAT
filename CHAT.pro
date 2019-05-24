#-------------------------------------------------
#
# Project created by QtCreator 2019-05-20T22:26:24
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CHAT
TEMPLATE = app


SOURCES += main.cpp\
    mainwin.cpp \
    filelist.cpp \
    udpchat.cpp


HEADERS  +=  mainwin.h \
    filelist.h \
    udpchat.h

FORMS    +=  mainwin.ui \
    filelist.ui

DISTFILES +=

RC_ICONS = robot.ico
