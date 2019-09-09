#ifndef TAB_H
#define TAB_H
#include"mainwindow.h"
void MainWindow::tab_init()
{
    this->configEditor = new tabCodeEditor();
    configEditor->setTabsClosable(true);
    connect(configEditor,SIGNAL(tabCloseRequested(int)),this,SLOT(removetab(int)));
    vLayout->addWidget(configEditor);
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
    MyHighLighter *highlighter = new MyHighLighter(temp->document());
    configEditor->setCurrentIndex(configEditor->indexOf(temp));
    configEditor->blankEditor = temp;
    count++;
}
#endif // TAB_H
