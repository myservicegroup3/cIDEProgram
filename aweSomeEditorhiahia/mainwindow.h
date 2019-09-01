﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "src/codeeditor.h"
#include "src/myhighlighter.h"
#include "src/typedef.h"
#include <QSettings>
class MainWindow : public QMainWindow,Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    //theme
    QString theme;

private slots:
    //theme
    //void setMainWindowStyle(QString backgroundColor, QString lineColor);
    void setTabWidgetStyle(QString foregroundColor, QString backgroundColor);
    void on_actionTommorrow_Night_triggered();




private:
     QString  filename;
     QString  filepath;
     QSettings settings;

    CodeEditor *configEditor;
    void on_save();
    //编译
    void precomp();
    bool is_changed;
private slots:
    void New();
    void open();
    void save();
    //编译
    void on_comp();
    void on_run();
    void on_change();


};

#endif // MAINWINDOW_H
