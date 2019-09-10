﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "codeeditor.h"
#include "myhighlighter.h"
#include "ui_mainwindow.h"
#include "redefine.h"
#include <Windows.h>
#include <QMenuBar>
#include<QMenu>
#include <QSettings>
#include <QPushButton>
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
   QMenu *pview = mbar->addMenu(u8"编辑");
   QMenu *pexeute=mbar->addMenu(u8"调试");
   QMenu *pcomment = mbar->addMenu(u8"注释");
   QMenu *psetting=mbar->addMenu(u8"设置");
   QMenu *pabout =mbar->addMenu(u8"关于");
   QToolBar * toolBar=addToolBar("toolBar");
      QToolBar * debugBar=addToolBar("debugBar");
      //调试
      QToolButton *b1 ;
       QToolButton *b2 ;
       QToolButton *b3;
          QToolButton *b4 ;
           QToolButton *b5 ;
             QToolButton *b8 ;
      QToolButton *b6 ;
        QToolButton *b7 ;


private:
   //模块化设置
    void buttonPics();//工具栏
     void debugbar_init();
    void setsearch();//搜索
    void edit_init();//视图
    void file_init();
    void tab_init();
    void about_init();
    void debug_init();
     void debugmenu_init();


private slots:
     //调试用
       void addpointtext();
       void deletepointtext();
       void findpointtext();

       void tpf11();
       void tpf12();
       void debugquit();
       void addpoint();
       void deletepoint();
       void jump();
       void printpoint();
       void debug_continue();



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
    void hidetoolbar();
   // void test();
    //复制
    void copy();
    void paste();
    void cut();



    void New();
    void open();
    void save();
    //编译
    void on_comp();
    void on_run();
    void on_change();
     void on_debug();

    //设置
    //主题
    void setting_init();
    void Tommorrow_Night_triggered();
    void Tommorrow_Light_triggered();
    void Solarized_Dark_triggered();
    void monokai_triggered();
    void solarized_triggered();
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
    //设置结束

    //tab测试
    void removetab(int index);

    void addPageSlot();
    //void removePageSlot();
    //void dragPageSlot();

        //隐藏注释
    void commenthide_init();
    void commenthide();
    void commentappear();





private:
    int count = 0;
    QString  filename;
    QString  filepath;
    QSettings settings;

    QLineEdit *addpointLineEdit;
    QLineEdit *deletepointLineEdit;
    QLineEdit *findpointLineEdit;
    QDialog *addDlg;
    QDialog *deleteDlg;
    QDialog *findpointDlg;


    QLineEdit *findLineEdit;

    QLineEdit *findLineEdit_1;
    QLineEdit *findLineEdit_2;

    QDialog *findDlg;
    QDialog *findDlg1;
    tabCodeEditor *configEditor;
    redefine *re;
//

    void on_save();
    bool is_changed;
};

#endif // MAINWINDOW_H