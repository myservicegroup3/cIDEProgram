#ifndef OTHERS_H
#define OTHERS_H

#include "mainwindow.h"


void MainWindow::about_init()
{
    QAction *ab=pabout->addAction(u8"开发人员");
    connect(ab,&QAction::triggered,[=]()
    {
        QMessageBox::about(this,"about",u8"开发人员：祁志洋，赵英健，刘俊杰，刘常思冰，黄啸嵩");
    });

}
/****************************新建Tabwidget**************************/
//QAction *pceshi = ptest->addAction("test");
//connect(pceshi, SIGNAL(triggered()), this, SLOT(addPageSlot()));
/**********************************************************/
#endif // OTHERS_H
