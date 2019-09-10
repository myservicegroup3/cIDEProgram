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
    codeeditor.cpp \
    myhighlighter.cpp \
    redefine.cpp

HEADERS  += mainwindow.h \
    setting.h \
    include.h \
    myhighlighter.h \
    codeeditor.h \
    toolbar.h \
    search.h \
    redefine.h \
    edit.h \
    debug.h \
    file.h \
    others.h \
    tab.h \
    commenthide.h
CONFIG +=c++11
FORMS    += mainwindow.ui \
    redefine.ui

RESOURCES += \
    img.qrc \
    keyword.qrc
