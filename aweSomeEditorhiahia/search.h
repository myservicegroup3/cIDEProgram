#ifndef SEARCH_H
#define SEARCH_H
#include "mainwindow.h"
#include "include.h"
//1、搜索功能
void MainWindow::setsearch()
{
    QAction *find1=pfind->addAction(u8"关键字搜索");
    //创建搜索窗口
    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr(u8"关键字搜索"));
    findLineEdit = new QLineEdit(findDlg);
    QLabel *lb = new QLabel(tr(u8"搜索"),findDlg);
    QPushButton *btn= new QPushButton(tr(u8"向前搜索"), findDlg);
    QPushButton *btn1= new QPushButton(tr(u8"向后搜索"), findDlg);
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
    QAction *remove1=pfind->addAction(u8"替换");
    //创建替换窗口
    findDlg1 = new QDialog(this);
    findDlg1->setWindowTitle(tr(u8"替换"));
    findLineEdit_1 = new QLineEdit(findDlg1);
    findLineEdit_2 = new QLineEdit(findDlg1);
    QLabel *lb1 = new QLabel(tr(u8"搜索"),findDlg);
    QLabel *lb2 = new QLabel(tr(u8"替换为:"),findDlg);
    QPushButton *btn_1= new QPushButton(tr(u8"向前捕捉"), findDlg1);
    QPushButton *btn_2= new QPushButton(tr(u8"向后捕捉"), findDlg1);
    QPushButton *btn_3= new QPushButton(tr(u8"替换"), findDlg1);
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

}
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


#endif // SEARCH_H
