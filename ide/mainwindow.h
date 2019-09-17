#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "codeeditor.h"
#include "myhighlighter.h"
#include "ui_mainwindow.h"
#include "redefine.h"
#include <Windows.h>
#include <QMenuBar>
#include <QMenu>
#include <QSettings>
#include <QPushButton>
#include <QRegExp>
class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/*******************菜单栏类，将其实现于mainwindow中*****************/
private:
    //添加菜单栏
    QMenuBar *mbar = menuBar();
    QMenu *pfile = mbar->addMenu(u8"文件");
    QMenu *pfind = mbar->addMenu(u8"搜索");
    QMenu *pview = mbar->addMenu(u8"编辑");
    QMenu *pexeute = mbar->addMenu(u8"调试");
    QMenu *pcomment = mbar->addMenu(u8"注释");
    QMenu *psetting = mbar->addMenu(u8"设置");
    QMenu *pabout = mbar->addMenu(u8"关于");

    //菜单栏项变量
    int count = 0;
    QString filename;
    QString filepath;
    QSettings settings;
    QString theme;
    QLineEdit *findLineEdit;
    QLineEdit *findLineEdit_1;
    QLineEdit *findLineEdit_2;
    QDialog *findDlg;
    QDialog *findDlg1;
    tabCodeEditor *configEditor;
    redefine *re;
    bool is_changed;



private:
    //菜单栏函数
    void buttonPics(); //工具栏
    void debugbar_init();
    void setsearch(); //搜索
    void edit_init(); //视图
    void file_init();
    void tab_init();
    void about_init();
    void debug_init();
    void debugmenu_init();
    void on_save();
private slots:
    //菜单栏槽函数
    void setTabWidgetStyle();
    void addPageSlot();
    void removetab(int index);

    //搜索
    void showFindText1();
    void showFindText2();
    void showFindText_1();
    void showFindText_2();
    void showFindText3();

    //编辑用
    void hidebar();
    void hidetoolbar();


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

    //隐藏注释
    void commenthide_init();
    void commenthide();
    void commentappear();


/*****************************菜单栏类结束******************************/


/*******************工具栏类，将其实现于mainwindow类中*********************/


private:
    QToolBar *toolBar = addToolBar("toolBar");
    QToolBar *debugBar = addToolBar("debugBar");

private:
    //调试工具栏
    QToolButton *b1;
    QToolButton *b2;
    QToolButton *b3;
    QToolButton *b4;
    QToolButton *b5;
    QToolButton *b8;
    QToolButton *b6;
    QToolButton *b7;

    //调试所用变量
    QLineEdit *addpointLineEdit;
    QLineEdit *deletepointLineEdit;
    QLineEdit *findpointLineEdit;
    QDialog *addDlg;
    QDialog *deleteDlg;
    QDialog *findpointDlg;
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
 /*****************************工具栏类结束******************************/



};

#endif // MAINWINDOW_H
