#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "src/codeeditor.h"
#include "src/myhighlighter.h"

#include <QSettings>
#include <QRegExp>
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
    void Tommorrow_Night_triggered();
    void Tommorrow_Light_triggered();

    void Solarized_Dark_triggered();
    void monokai_triggered();
    void solarized_triggered();
    void New();
    void open();
    void save();
    //编译
    void on_comp();
    void on_run();
    void on_change();




private:
     QString  filename;
     QString  filepath;
     QSettings settings;

    CodeEditor *configEditor;
    void on_save();
    //编译
    void precomp();
    bool is_changed;
};

#endif // MAINWINDOW_H
