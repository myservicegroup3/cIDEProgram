#-------------------------------------------------
#
# Project created by QtCreator 2015-09-17T10:51:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aweSomeEditorhiahia
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/codeeditor.cpp \
    src/myhighlighter.cpp

HEADERS  += mainwindow.h \
    src/codeeditor.h \
    src/myhighlighter.h \
    setting.h \
    include.h
CONFIG +=c++11
FORMS    += mainwindow.ui
