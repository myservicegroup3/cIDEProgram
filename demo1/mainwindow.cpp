#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);
    configEditor = new CodeEditor();
    configEditor->setMode(EDIT);
    gridLayout->addWidget(configEditor);
    MyHighLighter *highlighter = new MyHighLighter(configEditor->document());

    //文本内容在保存前是否发生变动
    is_changed = false;

    //添加菜单项，并为其设定快捷键
    //【文件菜单栏】
    file_menu = this->menuBar()->addMenu(u8"文件");
    new_file = new QAction(u8"新建文件",this);  //第一个参数是菜单项的文字，第二个参数是指向主体的指针
    new_file ->setShortcut(tr("ctrl+n"));   //设定快捷键
    file_menu ->addAction(new_file);        //关联 菜单栏 与 菜单项
    file_menu ->addSeparator();             //在文件下拉菜单上面显示一个分隔符

    open_file = new QAction(u8"打开文件",this);
    file_menu ->addAction(open_file);
    open_file ->setShortcut(tr("ctrl+o"));

    save_file = new QAction(u8"保存文件",this);
    file_menu ->addAction(save_file);
    save_file ->setShortcut(tr("ctrl+s"));

    exit_file = new QAction(u8"退出",this);
    file_menu->addAction(exit_file);

    //【编辑菜单栏】
    edit_menu = this->menuBar()->addMenu(u8"编辑");
    copy_edit = new QAction(u8"复制",this);
    copy_edit ->setShortcut(tr("ctrl+c"));
    edit_menu ->addAction(copy_edit);

    paste_edit = new QAction(u8"粘贴",this);
    paste_edit ->setShortcut(tr("ctrl+v"));
     edit_menu ->addAction(paste_edit);

    cut_edit = new QAction(u8"剪切",this);
    cut_edit ->setShortcut(tr("ctrl+x"));
    edit_menu ->addAction(cut_edit);

    allselect_edit = new QAction(u8"全选",this);
    allselect_edit ->setShortcut(tr("ctrl+a"));
    edit_menu ->addAction(allselect_edit);

    //【编译菜单栏】
    comp_menu = this->menuBar()->addMenu(u8"编译");
    comp_comp = new QAction(u8"编译",this); comp_menu->addAction(comp_comp);
    run_comp = new QAction(u8"运行",this);  comp_menu->addAction(run_comp);

    //【帮助菜单栏】
    help_menu = this->menuBar()->addMenu(u8"帮助");



    //【鼠标事件与函数关联】当鼠标点击exit_file 菜单的时候，执行on_exit()函数
    connect(exit_file,SIGNAL(triggered()),this,SLOT(on_exit()));
    connect(open_file,SIGNAL(triggered()),this,SLOT(on_open()));
    connect(save_file,SIGNAL(triggered()),this,SLOT(on_save()));
    connect(new_file,SIGNAL(triggered()),this,SLOT(on_new()));
    connect(copy_edit,SIGNAL(triggered()),this,SLOT(on_copy()));
    connect(paste_edit,SIGNAL(triggered()),this,SLOT(on_paste()));
    connect(cut_edit,SIGNAL(triggered()),this,SLOT(on_cut()));
    connect(allselect_edit,SIGNAL(triggered()),this,SLOT(on_allselect()));
    connect(text1,SIGNAL(textChanged()),this,SLOT(on_changed()));//当文本内容发生变化时，触发on_changed函数
    connect(comp_comp,SIGNAL(triggered()),this,SLOT(on_comp()));//当文本内容发生变化时，触发on_changed函数
    connect(run_comp,SIGNAL(triggered()),this,SLOT(on_run()));//当文本内容发生变化时，触发on_changed函数

}

MainWindow::~MainWindow()//析构函数
{
    delete text1;
    text1 = NULL;
}

void MainWindow::precomp()//预编译
{
    FILE *p = fopen(filename.toStdString().data(),"r");
    if(p == NULL) return ;
    QString cmd = filename +".c";
    FILE *p1 = fopen(cmd.toStdString().data(),"w");
    if(p1 == NULL) return ;
    QString str;
    while(!feof(p))
    {
        char buf[1024] = {0};
        fgets(buf,sizeof(buf),p);
        str += buf;
    }

    str.replace("包含","#include");
    str.replace("主函数","main");
    str.replace("整数","int");
    str.replace("开始","{");
    str.replace("收工","}");
    str.replace("。",";");
    str.replace("返回","return");
    str.replace("打印","printf");
    str.replace("输入输出","<stdio.h>");
    str.replace("无声的等待...","getchar()");

    fputs(str.toStdString().data(),p1);
    fclose(p);
    fclose(p1);
}

//程序退出
void MainWindow::on_exit()
{
    this ->close();
}
//打开文件
void MainWindow::on_open()
{
   filename =  QFileDialog::getOpenFileName(this,"打开");
   if(filename.isEmpty()) return ;//考虑用户选择取消的情景
   FILE *p = fopen(filename.toStdString().data(),"r");
   if(p == NULL) return ;
    QString str;
    while(!feof(p))
    {
        char buf[1024] = {0};
        fgets(buf,sizeof(buf),p);
        str += buf;
    }
    fclose(p);
    text1->setText(str);
    is_changed = false;
}
//保存文件
void MainWindow::on_save()
{
    if(filename.isEmpty())
    {
        filename = QFileDialog::getSaveFileName(this,"保存文件");
    }
    if(!filename.isEmpty())
    {
        FILE *p = fopen(filename.toStdString().data(),"w");
        if(p == NULL) return ;
        QString str = text1->toPlainText();
        fputs(str.toStdString().data(),p);
        fclose(p);
    }
}
//新建文件
void MainWindow::on_new()
{
    if(is_changed == true)
    {
        on_save();
        is_changed = false;
    }
    filename = "";
    text1->setText("");
}
//IDE的复制功能
void MainWindow::on_copy()
{
    text1->copy();
}

void MainWindow::on_paste()
{
    text1->paste();
}

void MainWindow::on_cut()
{
    text1->cut();
}

void MainWindow::on_allselect()
{
    text1->selectAll();
}

void MainWindow::on_changed()
{
    is_changed = true;
}
//编译并运行按钮
void MainWindow::on_comp()
{
    if (is_changed == true)//在点击编译按钮，如果文本内容发生变化，就自动保存
    {
        on_save();
    }
    precomp();//自动以预编译
    QString cmd;
    const char *s = filename.toStdString().data();
    cmd.sprintf("gcc -o %s.exe %s.c",s,s);
    system(cmd.toStdString().data());//先编译

    //如何删除那个临时文件呢
    cmd = filename.replace("/","\\") + ".c";
    remove(cmd.toStdString().data());


    cmd = filename + ".exe";
    system(cmd.toStdString().data());//再运行
}

void MainWindow::on_run()
{
    QString cmd;
    cmd = filename + ".exe";
    system(cmd.toStdString().data());
}
