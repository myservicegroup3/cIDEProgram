#ifndef MAINWINDOW_H
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
     QSettings settings;

    CodeEditor *configEditor;
    void on_save();
private slots:
    void New();
    void open();
    void save();


};

#endif // MAINWINDOW_H
