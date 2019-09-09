#include "mainwindow.h"
#include "setting.h"
#include "toolbar.h"
#include "search.h"
#include "redefine.h"
#include "edit.h"
#include <QMenuBar>
#include<QMenu>
#include<QAction>
#include<QDebug>
#include<QToolBar>
#include<QLabel>
#include<QStatusBar>
#include<QMessageBox>
#include<QDialog>
#include<QFileDialog>
#include<QFile>
#include<QLineEdit>
#include<QDialog>
#include<QPushButton>
#include<QPlainTextEdit>
#include <QTabWidget>
#include<QTabBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);
    this->setWindowIcon(QIcon(":/img/img/2.png"));

    /****************************初始化Tabwidget**************************/

    this->configEditor = new tabCodeEditor();
    configEditor->setTabsClosable(true);
    connect(configEditor,SIGNAL(tabCloseRequested(int)),this,SLOT(removetab(int)));
    vLayout->addWidget(configEditor);
    /*******************************************************************/

    /****************************新建prosses**************************/
    re = new redefine();
    /**********************************************************/

    /****************************新建Tabwidget**************************/
    //QAction *pceshi = ptest->addAction("test");
    //connect(pceshi, SIGNAL(triggered()), this, SLOT(addPageSlot()));
    /**********************************************************/



     /****************************设置**************************/
        setting_init();
     /**********************************************************/

     /***************************视图**************************/
        edit_init();
    /**********************************************************/



    MyHighLighter *highlighter = new MyHighLighter(configEditor->blankEditor->document());



    /****************************文件菜单栏**************************/


    //1.新建文件  //代码已完成，可测试
    QAction *pNew = pfile->addAction(u8"新建");
    pNew ->setShortcut(tr("ctrl+n"));
    connect(pNew,SIGNAL(triggered()),this,SLOT(New()));
    connect(pNew, SIGNAL(triggered()), this, SLOT(addPageSlot()));
    pfile->addSeparator();


    //2.打开文件,即读已写文件，已完成，可测试
    QAction *popen =pfile->addAction(u8"打开");
    popen ->setShortcut(tr("ctrl+o"));
    connect(popen,SIGNAL(triggered()),this,SLOT(open()));
    pfile->addSeparator();

    //3.保存为文件,代码已完成，可测试
    QAction *psave = pfile->addAction(u8"保存");
    psave ->setShortcut(tr("ctrl+s"));
    connect(psave,SIGNAL(triggered()),this,SLOT(save()));
    pfile->addSeparator();
   /**************************************************************/
    //复制
    QAction *copy_edit =pfile->addAction(u8"复制");
    copy_edit ->setShortcut(tr("ctrl+c"));
     connect(copy_edit,SIGNAL(triggered()),this,SLOT(copy()));

     QAction *paste_edit = pfile->addAction(u8"粘贴");
     paste_edit ->setShortcut(tr("ctrl+v"));
     connect(paste_edit,SIGNAL(triggered()),this,SLOT(paste()));

     QAction *cut_edit = pfile->addAction(u8"剪切");
     cut_edit ->setShortcut(tr("ctrl+x"));
     connect(cut_edit,SIGNAL(triggered()),this,SLOT(cut()));
    /***************************搜索********************************/
    setsearch();
    /**************************************************************/


   /**************************编译运行*********************************/
   //编译完成 ljj lcsb 测试可用
    QAction *comp = pexeute->addAction(u8"编译");
    QAction *run = pexeute->addAction(u8"运行");
    //connect(configEditor->,SIGNAL(textChanged()),this,SLOT(on_changed()));
    connect(comp,SIGNAL(triggered()),this,SLOT(on_comp()));
    connect(run,SIGNAL(triggered()),this,SLOT(on_run()));

    /**************************************************************/



    /***********************栏*************************************/


       //关于
       QAction *ab=pabout->addAction(u8"开发人员");
       connect(ab,&QAction::triggered,[=]()
       {
           QMessageBox::about(this,"about",u8"开发人员：祁志洋，赵英健，刘俊杰，刘常思冰，黄啸嵩");
       });
    /**************************************************************/


    /***************************工具栏*****************************/
       buttonPics();

   /**************************************************************/

}


MainWindow::~MainWindow()
{
}
void MainWindow :: addPageSlot()
{
    //定义一个QWidget.
    CodeEditor * temp = new CodeEditor;
    //blankWidget *temp = new blankWidget;
    //在当前页面的后面插入一个新的页面.
    configEditor->insertTab(configEditor->currentIndex()+1,temp,QIcon("Icons/2.png"),QString::number(count));
   //configEditor->insertTab(configEditor->currentIndex()+1,temp,QIcon("Icons/2.png"),QString::number(count));
            //显示新的页面
    configEditor->setCurrentIndex(configEditor->indexOf(temp));

    count++;
}
void MainWindow::New()
{
    if(is_changed == true)
    {
        save();
        is_changed = false;
    }
    filename = "";
    configEditor->blankEditor->setPlainText("");
}
void MainWindow::open()
{
    filename =  QFileDialog::getOpenFileName(this,u8"打开");
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
     configEditor->blankEditor->setPlainText(str);
     is_changed = false;
}
void MainWindow::save()
{
    if(filename.isEmpty())
    {
        filename = QFileDialog::getSaveFileName(this,u8"保存文件");
    }
    if(!filename.isEmpty())
    {
        FILE *p = fopen(filename.toStdString().data(),"w");
        if(p == NULL) return ;
        QString str =configEditor->blankEditor ->toPlainText();
        fputs(str.toStdString().data(),p);
        fclose(p);
    }
}
void MainWindow::copy()
{
    configEditor->blankEditor->copy();
}
void MainWindow::paste()
{
    configEditor->blankEditor->paste();
}
void MainWindow::cut()
{
    configEditor->blankEditor->cut();
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
    cmd = "gcc -o " + filepath.replace(QRegExp("\\..*$"),"") + ".exe " + filepath + ".cpp";
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
//视图


void MainWindow::hidestatus()
{

}


void MainWindow::test()
{

}

//搜索替换部分

void MainWindow::showFindText1()
{
    QString str = findLineEdit->text();
    if(!configEditor->blankEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr(u8"错误"),tr(u8"找不到%1").arg(str));
    }

}

void MainWindow::showFindText2()
{
    QString str = findLineEdit->text();
    if(!configEditor->blankEditor->find(str))
    {
            QMessageBox::warning(this,tr(u8"错误"),tr(u8"找不到%1").arg(str));
    }

}

void MainWindow::showFindText_1()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->blankEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr(u8"错误"),tr(u8"找不到%1").arg(str));
    }
}

void MainWindow::showFindText_2()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->blankEditor->find(str))
    {
            QMessageBox::warning(this,tr(u8"错误"),tr(u8"找不到%1").arg(str));
    }

}

void MainWindow::showFindText3()
{
    QString str = findLineEdit_1->text();
    QString str1 = findLineEdit_2->text();
    if(configEditor->blankEditor->textCursor().selectedText()==str)
    {
            configEditor->blankEditor->textCursor().insertText(str1);
    }
}
void MainWindow::removetab(int index)
{
   configEditor->removeTab(index);
};
