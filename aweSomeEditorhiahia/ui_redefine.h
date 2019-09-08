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
#include <QtWidgets/QSpacerItem>
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
    QToolButton *closeBtn;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *redefine)
    {
        if (redefine->objectName().isEmpty())
            redefine->setObjectName(QStringLiteral("redefine"));
        redefine->resize(1180, 252);
        redefine->setStyleSheet(QStringLiteral("background-color: rgb(230, 230, 230);"));
        centralWidget = new QWidget(redefine);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        closeBtn = new QToolButton(centralWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMaximumSize(QSize(30, 30));
        closeBtn->setStyleSheet(QStringLiteral("#closeBtn{border-image:url(:/img/img/close.png);}"));

        gridLayout->addWidget(closeBtn, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 160));
        textEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 2);

        redefine->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(redefine);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        redefine->setStatusBar(statusBar);

        retranslateUi(redefine);

        QMetaObject::connectSlotsByName(redefine);
    } // setupUi

    void retranslateUi(QMainWindow *redefine)
    {
        redefine->setWindowTitle(QApplication::translate("redefine", "redefine", nullptr));
        closeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class redefine: public Ui_redefine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDEFINE_H
