#ifndef DEBUG_H
#define DEBUG_H
#include "mainwindow.h"
#include <QDebug>
#include <QToolBar>
#include "include.h"

//编译运行

void MainWindow::on_debug()
{
    if (is_changed == true) //在点击编译按钮，如果文本内容发生变化，就自动保存
    {
        save();
        is_changed = false;
    }
    QString cmd;
    QString filepath = filename;
    cmd = "gcc -g " + filepath.replace(QRegExp("\\..*$"), "") + ".cpp" + " -o " + filepath.replace(QRegExp("\\..*$"), "") + ".exe";
    //filepath.replace(QRegExp("\\..*$"),"") + ".exe " + filepath + ".cpp";
    //qDebug() << "Success:write_cmd：" << cmd << endl;
    vLayout->addWidget(re);
    vLayout->setStretchFactor(configEditor, 2);
    vLayout->setStretchFactor(re, 1);
    re->show();

    re->write_cmd(cmd);
    FILE *stream ;
    if((stream = freopen("1.txt", "w", stdout)) == NULL)
    {
           qDebug()<<"error"<<endl;
           //exit(-1);
    }
    re->write_cmd("gdb");
    re->write_cmd("file " + filepath.replace(QRegExp("\\..*$"), ""));
    re->write_cmd("start");

    debugBar->setVisible(true);


}
void MainWindow::addpointtext()
{
    QString str =addpointLineEdit->text();
    re->write_cmd("b "+str);
    addDlg->close();
    re->write_cmd("call (int)fflush(0)");
}
void MainWindow::deletepointtext()
{
    QString str =deletepointLineEdit->text();
    re->write_cmd("clear "+str);
    deleteDlg->close();
    re->write_cmd("call (int)fflush(0)");
}
void MainWindow::findpointtext()
{
    QString str =findpointLineEdit->text();
    re->write_cmd("p "+str);
    findpointDlg->close();
    re->write_cmd("call (int)fflush(0)");

}
void MainWindow::debug_continue()
{
    re->write_cmd("c");
    re->write_cmd("call (int)fflush(0)");
}

void MainWindow::addpoint()
{

    addDlg = new QDialog(this);
    addDlg->setWindowTitle(tr(u8"增加断点"));
    addpointLineEdit = new QLineEdit(addDlg);
    QLabel *lb = new QLabel(tr(u8"增加断点行号"),addDlg);
    QPushButton *btn= new QPushButton(tr(u8"确定"), addDlg);
    QVBoxLayout *layout= new QVBoxLayout(addDlg);
    layout->addWidget(lb);
    layout->addWidget(addpointLineEdit);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked()), this, SLOT(addpointtext()));
    addDlg->show();


}
void MainWindow::deletepoint()
{
    deleteDlg = new QDialog(this);
    deleteDlg->setWindowTitle(tr(u8"删除断点"));
    deletepointLineEdit = new QLineEdit(deleteDlg);
    QLabel *lb = new QLabel(tr(u8"请输入断点行号"),deleteDlg);
    QPushButton *btn= new QPushButton(tr(u8"确定"), deleteDlg);
    QVBoxLayout *layout= new QVBoxLayout(deleteDlg);
    layout->addWidget(lb);
    layout->addWidget(deletepointLineEdit);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked()), this, SLOT(deletepointtext()));
    deleteDlg->show();
}

void MainWindow::printpoint()
{
    findpointDlg = new QDialog(this);
    findpointDlg->setWindowTitle(tr(u8"查看变量"));
    findpointLineEdit = new QLineEdit(findpointDlg);
    QLabel *lb = new QLabel(tr(u8"请输入变量名字"),findpointDlg);
    QPushButton *btn= new QPushButton(tr(u8"确定"), findpointDlg);
    QVBoxLayout *layout= new QVBoxLayout(findpointDlg);
    layout->addWidget(lb);
    layout->addWidget(findpointLineEdit);
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked()), this, SLOT(findpointtext()));
    findpointDlg->show();
}
void MainWindow::jump()
{
    re->write_cmd("finish");
    re->write_cmd("call (int)fflush(0)");
}
void MainWindow::tpf11()
{

    re->write_cmd("step");
    re->write_cmd("call (int)fflush(0)");
}
void MainWindow::tpf12()
{

    re->write_cmd("next");
    re->write_cmd("call (int)fflush(0)");
}
void MainWindow::debugquit()
{
    re->write_cmd("q");
    debugBar->setVisible(false);
}
void MainWindow::debugbar_init()
{

    debugBar->setVisible(false);

    debugBar->setFixedSize(600, 50);

   b1 = new QToolButton(this);
   b1->setToolTip("逐语句");
    b1->setIcon(QIcon(":/img/img/step.png"));
    b1->setStyleSheet("background-image:url(img/2.png)");

    b1->setStyleSheet("QToolButton{background-image:url(:/img/tree.jpg);}"       // 按键本色
                      "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
                      "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b1->setFixedSize(45, 30);
    debugBar->addWidget(b1);
    connect(b1, SIGNAL(clicked()), this, SLOT(tpf11()));

   b2 = new QToolButton(this);
   b2->setToolTip("逐过程");
    b2->setIcon(QIcon(":/img/img/next.png"));
    b2->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b2->setFixedSize(45, 30);
    connect(b2, SIGNAL(clicked()), this, SLOT(tpf12()));
    debugBar->addWidget(b2);


    b3 = new QToolButton(this);
    //littlePic->addWidget(b3);
    b3->setToolTip("跳出");
    b3->setIcon(QIcon(":/img/img/jump.png"));
    b3->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b3->setFixedSize(45, 30);
    connect(b3, SIGNAL(clicked()), this, SLOT(jump()));
    debugBar->addWidget(b3);
    debugBar->addSeparator();

    b4 = new QToolButton(this);
    b4->setToolTip("增加断点");
    b4->setIcon(QIcon(":/img/img/add.png"));
    //littlePic->addWidget(b4);
    b4->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b4->setFixedSize(45, 30);
    connect(b4, SIGNAL(clicked()), this, SLOT(addpoint()));
    debugBar->addWidget(b4);


   b5 = new QToolButton(this);
   b5->setToolTip("删除断点");
    b5->setIcon(QIcon(":/img/img/delete.png"));
    //littlePic->addWidget(b4);
    b5->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b5->setFixedSize(45, 30);
    connect(b5, SIGNAL(clicked()), this, SLOT(deletepoint()));
    debugBar->addWidget(b5);

    debugBar->addSeparator();

    b8 = new QToolButton(this);
    b8->setToolTip("继续执行");
    b8->setIcon(QIcon(":/img/img/continue.png"));
    //littlePic->addWidget(b4);
    b8->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b8->setFixedSize(45, 30);
    connect(b8, SIGNAL(clicked()), this, SLOT(debug_continue()));
    debugBar->addWidget(b8);


    b6 = new QToolButton(this);
    b6->setToolTip("查看变量值");
    b6->setIcon(QIcon(":/img/img/find.png"));
    //littlePic->addWidget(b4);
    b6->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b6->setFixedSize(45, 30);
    connect(b6, SIGNAL(clicked()), this, SLOT(printpoint()));
    debugBar->addWidget(b6);
    debugBar->addSeparator();

    b7 = new QToolButton(this);
    b7->setToolTip("关闭调试");
    b7->setIcon(QIcon(":/img/img/debugclose.png"));
    //littlePic->addWidget(b5);
    b7->setStyleSheet(
        "QToolButton:hover{background-color:white; color: black;}" // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 170, 255); border-style: inset; }");
    b7->setFixedSize(45, 30);
    connect(b7, SIGNAL(clicked()), this, SLOT(debugquit()));
    debugBar->addWidget(b7);

    //connect(pf11->menuAction(),SIGNAL(triggered()),this,SLOT(on_comp()));
    //connect(pf11->menuAction(),SIGNAL(triggered()),this,SLOT(on_comp()));
}
#endif // DEBUG_H
