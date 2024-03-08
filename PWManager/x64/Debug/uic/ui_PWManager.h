/********************************************************************************
** Form generated from reading UI file 'PWManager.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PWMANAGER_H
#define UI_PWMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PWManagerClass
{
public:
    QWidget *centralWidget;
    QPushButton *login;
    QTextEdit *username;
    QTextEdit *password;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PWManagerClass)
    {
        if (PWManagerClass->objectName().isEmpty())
            PWManagerClass->setObjectName("PWManagerClass");
        PWManagerClass->resize(601, 400);
        centralWidget = new QWidget(PWManagerClass);
        centralWidget->setObjectName("centralWidget");
        login = new QPushButton(centralWidget);
        login->setObjectName("login");
        login->setGeometry(QRect(260, 190, 75, 24));
        username = new QTextEdit(centralWidget);
        username->setObjectName("username");
        username->setGeometry(QRect(240, 60, 141, 31));
        password = new QTextEdit(centralWidget);
        password->setObjectName("password");
        password->setGeometry(QRect(240, 120, 141, 31));
        PWManagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PWManagerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 601, 22));
        PWManagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PWManagerClass);
        mainToolBar->setObjectName("mainToolBar");
        PWManagerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PWManagerClass);
        statusBar->setObjectName("statusBar");
        PWManagerClass->setStatusBar(statusBar);

        retranslateUi(PWManagerClass);

        QMetaObject::connectSlotsByName(PWManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PWManagerClass)
    {
        PWManagerClass->setWindowTitle(QCoreApplication::translate("PWManagerClass", "PWManager", nullptr));
        login->setText(QCoreApplication::translate("PWManagerClass", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PWManagerClass: public Ui_PWManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWMANAGER_H
