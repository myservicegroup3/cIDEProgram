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
#include<QLineEdit>
#include<QDialog>
#include<QPushButton>
#include<QPlainTextEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setupUi(this);
    configEditor = new CodeEditor();
    configEditor->colorCount();

    gridLayout->addWidget(configEditor);
    MyHighLighter *highlighter = new MyHighLighter(configEditor->document());

    //初始设置
    int windowWidth = settings.value("windowWidth", 1200).toInt();
    int windowHeight = settings.value("windowHeight", 900).toInt();
    MainWindow::resize(windowWidth, windowHeight);
    setTabWidgetStyle("#839496", "#fdf6e3");

/*
     //添加菜单栏
    QMenuBar *mbar=menuBar();


    //添加菜单项
    QMenu *pfile=mbar->addMenu(u8"文件");
    QMenu *pfind =mbar->addMenu(u8"搜索");
    QMenu *pview = mbar->addMenu(u8"视图");
    QMenu *pexeute=mbar->addMenu(u8"运行");
    QMenu *psetting=mbar->addMenu(u8"设置");
    QMenu *pabout =mbar->addMenu(u8"关于");

*/

    //设置
    //1主题
    QMenu *ptheme = psetting->addMenu(u8"主题");
    QAction *ptheme1 = ptheme->addAction("1");

    connect(ptheme1,SIGNAL(triggered()),this,SLOT(Tommorrow_Night_triggered()));
    QAction *ptheme2 = ptheme->addAction("2");
    connect(ptheme2,SIGNAL(triggered()),this,SLOT(Tommorrow_Light_triggered()));
    QAction *ptheme3 = ptheme->addAction("3");
    connect(ptheme3,SIGNAL(triggered()),this,SLOT(Solarized_Dark_triggered()));
    QAction *ptheme4 = ptheme->addAction("4");
    connect(ptheme4,SIGNAL(triggered()),this,SLOT(monokai_triggered()));
    QAction *ptheme5 = ptheme->addAction("5");
    connect(ptheme5,SIGNAL(triggered()),this,SLOT(solarized_triggered()));
    //2字体大小
    QMenu *pword = psetting->addMenu(u8"字体大小");
    QAction *pword1 = pword->addAction("1");
    connect(pword1,SIGNAL(triggered()),this,SLOT(setfontsize1()));
    QAction *pword2 = pword->addAction("2");
     connect(pword2,SIGNAL(triggered()),this,SLOT(setfontsize2()));
    QAction *pword3 = pword->addAction("3");
     connect(pword3,SIGNAL(triggered()),this,SLOT(setfontsize3()));
    QAction *pword4 = pword->addAction("4");
     connect(pword4,SIGNAL(triggered()),this,SLOT(setfontsize4()));
    //字体风格
    QMenu *pwordtheme = psetting->addMenu(u8"字体风格");
    QAction *pwordtheme1 = pwordtheme->addAction("1");
    connect(pwordtheme1,SIGNAL(triggered()),this,SLOT(setfontheme1()));
    QAction *pwordtheme2 = pwordtheme->addAction("2");
    connect(pwordtheme2,SIGNAL(triggered()),this,SLOT(setfontheme2()));
    QAction *pwordtheme3 = pwordtheme->addAction("3");
    connect(pwordtheme3,SIGNAL(triggered()),this,SLOT(setfontheme3()));
    QAction *pwordtheme4 = pwordtheme->addAction("4");
    connect(pwordtheme4,SIGNAL(triggered()),this,SLOT(setfontheme4()));


    //视图
    QAction *phide = pview->addAction(u8"隐藏菜单栏");
    phide ->setShortcut(tr("ctrl+h"));
    connect(phide,SIGNAL(triggered()),this,SLOT(hidebar()));

    //文件菜单栏
    //1.新建文件  //代码已完成，可测试
    QAction *pNew = pfile->addAction(u8"新建");
    pNew ->setShortcut(tr("ctrl+n"));
    connect(pNew,SIGNAL(triggered()),this,SLOT(New()));
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
   //文件部分完结，下面建立搜索栏

    
    //1、搜索功能
    QAction *find1=pfind->addAction("关键字搜索");
    //创建搜索窗口
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("关键字搜索"));
    findLineEdit = new QLineEdit(findDlg);
    QLabel *lb = new QLabel(tr("搜索"),findDlg);
    QPushButton *btn= new QPushButton(tr("向前搜索"), findDlg);
    QPushButton *btn1= new QPushButton(tr("向后搜索"), findDlg);
    QVBoxLayout *layout= new QVBoxLayout(findDlg);
    layout->addWidget(lb);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    layout->addWidget(btn1);




    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText1()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(showFindText2()));

    connect(find1,&QAction::triggered,[=]()
    {
        findDlg->show();
    });

    //2、替换功能
    QAction *remove1=pfind->addAction("替换");
    //创建替换窗口
    findDlg1 = new QDialog(this);
    findDlg1->setWindowTitle(tr("替换"));
    findLineEdit_1 = new QLineEdit(findDlg1);
    findLineEdit_2 = new QLineEdit(findDlg1);
    QLabel *lb1 = new QLabel(tr("搜索"),findDlg);
    QLabel *lb2 = new QLabel(tr("替换为:"),findDlg);
    QPushButton *btn_1= new QPushButton(tr("向前捕捉"), findDlg1);
    QPushButton *btn_2= new QPushButton(tr("向后捕捉"), findDlg1);
    QPushButton *btn_3= new QPushButton(tr("替换"), findDlg1);
    QVBoxLayout *layout1= new QVBoxLayout(findDlg1);
    layout1->addWidget(lb1);
    layout1->addWidget(findLineEdit_1);
    layout1->addWidget(lb2);
    layout1->addWidget(findLineEdit_2);
    layout1->addWidget(btn_1);
    layout1->addWidget(btn_2);
    layout1->addWidget(btn_3);
    connect(btn_1, SIGNAL(clicked()), this, SLOT(showFindText_1()));
    connect(btn_2, SIGNAL(clicked()), this, SLOT(showFindText_2()));
    connect(btn_3, SIGNAL(clicked()), this, SLOT(showFindText3()));

    connect(remove1,&QAction::triggered,[=]()
    {
        findDlg1->show();
    });

   //搜索部分完结，接下来完成编译运行

   
   //编译完成 ljj lcsb 测试可用
    QAction *comp = pexeute->addAction(u8"编译");
    QAction *run = pexeute->addAction(u8"运行");
    //connect(configEditor->toPlainText(),SIGNAL(textChanged()),this,SLOT(on_changed()));
    connect(comp,SIGNAL(triggered()),this,SLOT(on_comp()));
    connect(run,SIGNAL(triggered()),this,SLOT(on_run()));

   //编译运行部分完成，接下来完成设置



   //工具栏，添加快捷方式
       QToolBar * toolBar=addToolBar("toolBar");
       toolBar->addAction(pNew);
       toolBar->addAction(popen);

   //状态栏，我准备在这里显示编译成功与否
       QStatusBar *sBar =statusBar();
       QLabel *label =new QLabel(this);
       label->setText(u8"编译");
       sBar->addWidget(label);
       sBar->addWidget(new QLabel("2",this));

       //关于
       QAction *ab=pabout->addAction(u8"开发人员");
       connect(ab,&QAction::triggered,[=]()
       {
           QMessageBox::about(this,"about",u8"开发人员：祁志洋，赵英健，刘俊杰，刘常思冰，黄啸嵩");
       });


}

MainWindow::~MainWindow()
{
}

void MainWindow::New()
{
      filepath= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
      if(filepath.isEmpty()==false)
      {
          QFile file;//创建文件对象
          file.setFileName(filepath);
          bool isok=file.open(QIODevice::WriteOnly);
          file.close();
      }
}
void MainWindow::open()
{
    filepath= QFileDialog::getOpenFileName(
                this,
                "open",
                "../",
                "souce(*cpp *h);;Text(*.txt)"
                );
     if (filepath.isEmpty()==false)
     {    QFile file (filepath);
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
          filepath= QFileDialog::getSaveFileName(this,"save","../","souce(*cpp *h);;Text(*.txt)");
          if(filepath.isEmpty()==false)
          {
              QFile file;//创建文件对象
              file.setFileName(filepath);
              bool isok=file.open(QIODevice::WriteOnly);
              if(isok==true)
              {
              QString str=configEditor->toPlainText();
              file.write(str.toUtf8());
              }
              file.close();
          }
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
    if(is_changed == true)
    {








    }
    QString cmd;
    cmd = "gcc -o " + filepath.replace(QRegExp("\\..*$"),"") + ".exe " + filepath + ".cpp";
    system(cmd.toStdString().data());//编译
    //运行
    cmd = filepath + ".exe";
    system(cmd.toStdString().data());
}
//运行
void MainWindow::on_run()
{
    QString cmd;
    cmd = filepath.replace(QRegExp("\\..*$"),"") + ".exe";
    system(cmd.toStdString().data());
}
//视图
void MainWindow::hidebar()
{
    if (mbar->height() > 0){
        mbar->setMaximumHeight(0);
    } else {
        mbar->setMaximumHeight(100);
    }
}
//主题和字体

void MainWindow::setTabWidgetStyle(QString foregroundColor, QString backgroundColor){
    QString stylesheet = "QPlainTextEdit {"
                "background-color: " +  backgroundColor  +";"
                "color:" + foregroundColor  +";"

                "selection-background-color: #404f4f;"
                "font-family: \"Consolas\";"
                "font-size:21pt;"
             "}"

     ;
    configEditor->setStyleSheet(stylesheet);
}

void MainWindow::setfontheme1()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-family: \"Consolas\";"

             "}"

     ;
    configEditor->setStyleSheet(stylesheet);
}
void MainWindow::setfontheme2()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-family: \"Anonymous Pro\";"

             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontheme3()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-family: \"Calibri\";"

             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontheme4()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-family: \"Courier\";"

             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontsize1()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-size:12pt;"
             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontsize2()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-size:16pt;"
             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontsize3()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-size:20pt;"
             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::setfontsize4()
{
    QString stylesheet = "QPlainTextEdit {"
                "font-size:24pt;"
             "}"

     ;
    configEditor->setStyleSheet(stylesheet);

}
void MainWindow::Tommorrow_Night_triggered()
{
    theme = "tomorrowNight";
    settings.setValue("theme", "tomorrowNight");
    QString fgc = "#c5c8c6";
    QString bgc = "#1d1f21";
    QString lc = "#282a2e";

    setTabWidgetStyle(fgc, bgc);
    //setLineNumStyle(lc, fgc);
    //setOverViewStyle(lc, fgc);

    //updateHighlighterTheme();

   // lineColor = QColor(40, 42, 46);
   // highlightCurrentLine();
}
void MainWindow:: Tommorrow_Light_triggered()
{
    theme = "tomorrowLight";
    settings.setValue("theme","tommorowLight");
    QString fgc = "#4d4d4c";
    QString bgc = "#ffffff";
    QString lc =  "#282a2e";
    setTabWidgetStyle(fgc, bgc);
    //configEditor-
    //CodeEditor->updatecolor(lc);

}
void MainWindow ::Solarized_Dark_triggered()
{
    theme = "solarizedDark";
    settings.setValue("theme", "solarizedDark");
    QString fgc = "#839496";
    QString bgc = "#002b36";
    QString lc = "#073642";
    setTabWidgetStyle(fgc, bgc);



}

void MainWindow ::monokai_triggered()
{
    theme = "monokai";
   settings.setValue("theme", "monokai");
   QString fgc = "#e0e0e0";
   QString bgc = "#272822";
   //QString lc = "#32332c";
   setTabWidgetStyle(fgc, bgc);
}
void MainWindow::solarized_triggered()
{
   theme = "solarized";
   settings.setValue("theme", "solarized");
   QString fgc = "#839496";
   QString bgc = "#fdf6e3";
   //QString lc = "#eee7d5";
   setTabWidgetStyle(fgc, bgc);

}


//搜索替换部分

void MainWindow::showFindText1()
{
    QString str = findLineEdit->text();
    if(!configEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText2()
{
    QString str = findLineEdit->text();
    if(!configEditor->find(str))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText_1()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->find(str,QTextDocument::FindBackward))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }
}

void MainWindow::showFindText_2()
{
    QString str = findLineEdit_1->text();
    if(!configEditor->find(str))
    {
            QMessageBox::warning(this,tr("错误"),tr("找不到%1").arg(str));
    }

}

void MainWindow::showFindText3()
{
    QString str = findLineEdit_1->text();
    QString str1 = findLineEdit_2->text();
    if(configEditor->textCursor().selectedText()==str)
    {
            configEditor->textCursor().insertText(str1);
    }
}
