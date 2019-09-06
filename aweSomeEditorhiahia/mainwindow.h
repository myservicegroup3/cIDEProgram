#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "src/codeeditor.h"
#include "src/myhighlighter.h"
#include <QMenuBar>
#include<QMenu>
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
    //添加菜单栏
   QMenuBar *mbar=menuBar();


   //添加菜单项
   QMenu *pfile=mbar->addMenu(u8"文件");
   QMenu *pfind =mbar->addMenu(u8"搜索");
   QMenu *pview = mbar->addMenu(u8"视图");
   QMenu *pexeute=mbar->addMenu(u8"运行");
   QMenu *psetting=mbar->addMenu(u8"设置");
   QMenu *pabout =mbar->addMenu(u8"关于");

private slots:

    //theme
    //void setMainWindowStyle(QString backgroundColor, QString lineColor);
    void setTabWidgetStyle();
    //QString foregroundColor, QString backgroundColor


    //搜索
    void showFindText1();
    void showFindText2();
    void showFindText_1();
    void showFindText_2();
    void showFindText3();

    void hidebar();
    //


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
    //字体大小修改
    void setfontsize1();
    void setfontsize2();
    void setfontsize3();
    void setfontsize4();
    //字体风格修改
    void setfontheme1();
    void setfontheme2();
    void setfontheme3();
    void setfontheme4();




private:
     QString  filename;
     QString  filepath;
     QSettings settings;
    QLineEdit *findLineEdit;
    QLineEdit *findLineEdit_1;
    QLineEdit *findLineEdit_2;
    QDialog *findDlg;
    QDialog *findDlg1;
 
    

    CodeEditor *configEditor;
    void on_save();
    //编译
    void precomp();
    bool is_changed;
};

#endif // MAINWINDOW_H
