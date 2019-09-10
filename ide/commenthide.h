#ifndef COMMENTHIDE_H
#define COMMENTHIDE_H
#include "mainwindow.h"
#include <QTextCharFormat>

QTextCharFormat multiLineCommentFormat;


void MainWindow::commenthide_init()
{
    QAction *commenthide = pcomment->addAction(u8"隐藏注释");
    QAction *commentappear = pcomment->addAction(u8"显示注释");
    connect(commenthide,SIGNAL(triggered()),this,SLOT(commenthide()));
    connect(commentappear,SIGNAL(triggered()),this,SLOT(commentappear()));
}

void MainWindow::commenthide()
{
    QRegExp comment_singal = QRegExp("//[^\n]*");
    QRegExp comment_start = QRegExp("/\\*(.*(\n)*)*\\*/");
    QString text = configEditor->blankEditor->toPlainText();
    text.replace(comment_singal,"");
    text.replace(comment_start,"");
    configEditor->blankEditor->setPlainText(text);
}

void MainWindow::commentappear()
{
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
}

#endif // COMMENTHIDE_H
