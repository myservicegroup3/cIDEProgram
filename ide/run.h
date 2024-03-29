#ifndef RUN_H
#define RUN_H

#include "mainwindow.h"
#include <QDebug>
#include <QToolBar>

void MainWindow::debug_init()
{
   //编译运行

     QAction *comp = pexeute->addAction(u8"编译");
     QAction *run = pexeute->addAction(u8"运行");
     QAction *debug = pexeute->addAction(u8"调试");
     //connect(configEditor->,SIGNAL(textChanged()),this,SLOT(on_changed()));
     connect(comp,SIGNAL(triggered()),this,SLOT(on_comp()));
     connect(run,SIGNAL(triggered()),this,SLOT(on_run()));
          connect(debug,SIGNAL(triggered()),this,SLOT(on_debug()));


}

//编译
//判断代码是否被修改
void MainWindow::on_change()
{
    is_changed = true;
}
//编译运行

void MainWindow::on_comp()
{
    if (is_changed == true)//在点击编译按钮，如果文本内容发生变化，就自动保存
    {
        save();
        is_changed = false;
    }
    QString cmd;
    QString filepath = filename;
    cmd = "gcc -o " + filepath.replace(QRegExp("\\..*$"),"") + ".exe " + filepath + ".c";
    //re->move(50,450);
    //re->setParent(this);
    vLayout->addWidget(re);
    vLayout->setStretchFactor(configEditor,2);
    vLayout->setStretchFactor(re,1);
    re->show();
    re->write_cmd(cmd);
}
//运行
void MainWindow::on_run()
{
    QString cmd;
    QString filepath = filename;
    cmd = filepath.replace(QRegExp("\\..*$"),"") + ".exe";
    vLayout->addWidget(re);
    vLayout->setStretchFactor(configEditor,2);
    vLayout->setStretchFactor(re,1);
    re->show();
    system(cmd.toStdString().data());
}
#endif // RUN_H
