#include "mainwindow.h"
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
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);
    configEditor = new CodeEditor();
    configEditor->setMode(EDIT);
    gridLayout->addWidget(configEditor);
    MyHighLighter *highlighter = new MyHighLighter(configEditor->document());

    //窗口大小设置
        int windowWidth = settings.value("windowWidth", 1200).toInt();
        int windowHeight = settings.value("windowHeight", 900).toInt();
        MainWindow::resize(windowWidth, windowHeight);


     //添加菜单栏
    QMenuBar *mbar=menuBar();
    //添加菜单项
    QMenu *pfile=mbar->addMenu("文件");
    QMenu *pfind =mbar->addMenu("搜索");
    QMenu *pexeute=mbar->addMenu("运行");
    QMenu *psetting=mbar->addMenu("设置");
    QMenu *pabout =mbar->addMenu("关于");

    //关于
    QAction *ab=pabout->addAction("开发人员");
    connect(ab,&QAction::triggered,[=]()
    {
        QMessageBox::about(this,"about","开发人员：七只羊，赵英健，刘俊杰，刘常思冰，黄啸嵩");
    });


    //文件菜单栏
    //1.新建文件  //代码已完成，可测试
    QAction *pNew = pfile->addAction("新建");
    pNew ->setShortcut(tr("ctrl+n"));
    connect(pNew,SIGNAL(triggered()),this,SLOT(New()));
    pfile->addSeparator();


    //2.打开文件,即读已写文件，已完成，可测试
    QAction *popen =pfile->addAction("打开");
    popen ->setShortcut(tr("ctrl+o"));
    connect(popen,SIGNAL(triggered()),this,SLOT(open()));
    pfile->addSeparator();

    //3.保存为文件,代码已完成，可测试
    QAction *psave = pfile->addAction("保存");
    psave ->setShortcut(tr("ctrl+s"));
    connect(psave,SIGNAL(triggered()),this,SLOT(save()));
    pfile->addSeparator();
   //文件部分完结，下面建立搜索栏


   //搜索部分完结，接下来完成编译运行
  /* QAction *pcomp=pexeute->addAction("编译");
   pcomp->setShortcut(tr("ctrl+"));
   connect(pcomp,&QAction::triggered,[=](){
       if(ifChange==true)
       {
           save();
       }
       //预编译
       FILE *p=fopen(filename.toStdString().data(),"r");
         if(p==NULL) return;
         QString cmd=filename+".c";
         FILE *p1=fopen(cmd.toStdString().data(),"w");
         if(p1==NULL) return;
         QString str;
         while (!feof(p))
         {
            char s[1024]={'\0'};
            fgets(s,sizeof(s),p);
            str+=s;
         }
         fputs(str.toStdString().data(),p1);
         fclose(p);
         fclose(p1);


       //编译
       const char *s=filename.toStdString().data();
       cmd.sprintf("gcc -o %s.exe %s.c",s,s);
       system(cmd.toStdString().data());
   });
*/
   //编译运行部分完成，接下来完成设置



   //工具栏，添加快捷方式
       QToolBar * toolBar=addToolBar("toolBar");
       toolBar->addAction(pNew);
       toolBar->addAction(popen);

   //状态栏，我准备在这里显示编译成功与否
       QStatusBar *sBar =statusBar();
       QLabel *label =new QLabel(this);
       label->setText("编译");
       sBar->addWidget(label);
       sBar->addWidget(new QLabel("2",this));


}
void MainWindow::New()
{
      QString path= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
      if(path.isEmpty()==false)
      {
          QFile file;//创建文件对象
          file.setFileName(path);
          bool isok=file.open(QIODevice::WriteOnly);
          file.close();
      }
}
void MainWindow::open()
{
    QString path= QFileDialog::getOpenFileName(
                this,
                "open",
                "../",
                "souce(*cpp *h);;Text(*.txt)"
                );
     if (path.isEmpty()==false)
     {    QFile file (path);
     bool isok =file.open(QIODevice::ReadOnly);
     if(isok==true)
     {
         //读文件
     QByteArray array= file.readAll();
     configEditor->appendPlainText(array);
     }
     }
}
void MainWindow::save()
{
          QString path= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
          if(path.isEmpty()==false)
          {
              QFile file;//创建文件对象
              file.setFileName(path);
              bool isok=file.open(QIODevice::WriteOnly);
              if(isok==true)
              {
              QString str=configEditor->toPlainText();
              file.write(str.toUtf8());
              }
              file.close();
          }
}
MainWindow::~MainWindow()
{
}
