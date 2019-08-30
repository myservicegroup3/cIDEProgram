#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>    //文本
#include <QMenu>        //加入菜单
#include <QMenuBar>     //加入菜单栏
#include <QAction>      //加入菜单栏
#include <QFileDialog>
#include "ui_mainwindow.h"
#include "src/codeeditor.h"
#include "src/myhighlighter.h"
#include "src/typedef.h"

class MainWindow : public QMainWindow,Ui::MainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    bool is_changed;
    QString  filename;   //当前文件的名字
    QTextEdit *text1;   //中央的TextEdit控件

    //文件菜单
    QMenu *file_menu;   //文件菜单
    QAction *new_file;   //新建文件菜单项
    QAction *open_file;   //打开文件菜单项
    QAction *save_file;   //保存文件菜单项
    QAction *exit_file;   //退出文件菜单项

    //编辑菜单
    QMenu *edit_menu;   //编辑菜单
    QAction *copy_edit;   //编辑菜单的复制按钮
    QAction *paste_edit;
    QAction *cut_edit;
    QAction *allselect_edit;

    QMenu *help_menu;   //帮助菜单

    //编译菜单
    QMenu *comp_menu;   //编译菜单
    QAction *comp_comp;   //编译按钮
    QAction *run_comp;   //运行按钮


    void precomp();
private:
    void on_exit();//在QT编辑环境，安装ALT+ENTER，出现提示再按一次回车
    void on_open();
    void on_save();
    void on_new();
    void on_copy();
    void on_paste();
    void on_cut();
    void on_allselect();
    void on_changed();
    void on_comp();
    void on_run();
    CodeEditor *configEditor;
};

#endif // MAINWINDOW_H
