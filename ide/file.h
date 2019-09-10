#ifndef FILE_H
#define FILE_H
#include "mainwindow.h"
#include "run.h"
#include <QTabWidget>
#include<QTabBar>


void MainWindow::file_init()
{
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


#endif // FILE_H
