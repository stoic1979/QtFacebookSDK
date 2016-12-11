#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T19:10:39
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtFacebookSDK
TEMPLATE = app


SOURCES += main.cpp \
           mainwindow.cpp \
           facebookwebview.cpp \
           facebook.cpp

HEADERS  += mainwindow.h \
           facebookwebview.h \
           facebook.h

FORMS    += mainwindow.ui
