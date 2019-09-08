/********************************************************************************
** Form generated from reading UI file 'redefine.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDEFINE_H
#define UI_REDEFINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_redefine
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Clear;
    QToolButton *closeBtn;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *redefine)
    {
        if (redefine->objectName().isEmpty())
            redefine->setObjectName(QStringLiteral("redefine"));
        redefine->resize(819, 287);
        centralWidget = new QWidget(redefine);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));

        gridLayout->addWidget(pushButton_Clear, 0, 2, 1, 1);

        closeBtn = new QToolButton(centralWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMaximumSize(QSize(50, 50));

        gridLayout->addWidget(closeBtn, 0, 4, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 160));

        gridLayout->addWidget(textEdit, 1, 0, 1, 4);

        redefine->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(redefine);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 23));
        redefine->setMenuBar(menuBar);
        statusBar = new QStatusBar(redefine);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        redefine->setStatusBar(statusBar);

        retranslateUi(redefine);

        QMetaObject::connectSlotsByName(redefine);
    } // setupUi

    void retranslateUi(QMainWindow *redefine)
    {
        redefine->setWindowTitle(QApplication::translate("redefine", "redefine", nullptr));
        pushButton_Clear->setText(QApplication::translate("redefine", "\346\270\205\347\251\272\346\230\276\347\244\272\346\240\217", nullptr));
        closeBtn->setText(QApplication::translate("redefine", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class redefine: public Ui_redefine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDEFINE_H
