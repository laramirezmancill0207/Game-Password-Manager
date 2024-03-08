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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PWManagerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QFormLayout *formLayout;
    QLabel *usernameLabel;
    QLineEdit *username;
    QLabel *passwordLabel;
    QLineEdit *password;
    QPushButton *login;
    QLabel *loginMessage;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PWManagerClass)
    {
        if (PWManagerClass->objectName().isEmpty())
            PWManagerClass->setObjectName("PWManagerClass");
        PWManagerClass->resize(805, 683);
        centralWidget = new QWidget(PWManagerClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(100);
        formLayout->setVerticalSpacing(100);
        formLayout->setContentsMargins(175, 100, 175, 100);
        usernameLabel = new QLabel(centralWidget);
        usernameLabel->setObjectName("usernameLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, usernameLabel);

        username = new QLineEdit(centralWidget);
        username->setObjectName("username");

        formLayout->setWidget(1, QFormLayout::FieldRole, username);

        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName("passwordLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        password = new QLineEdit(centralWidget);
        password->setObjectName("password");

        formLayout->setWidget(2, QFormLayout::FieldRole, password);

        login = new QPushButton(centralWidget);
        login->setObjectName("login");
        login->setIconSize(QSize(16, 16));

        formLayout->setWidget(3, QFormLayout::FieldRole, login);

        loginMessage = new QLabel(centralWidget);
        loginMessage->setObjectName("loginMessage");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginMessage->sizePolicy().hasHeightForWidth());
        loginMessage->setSizePolicy(sizePolicy);
        loginMessage->setMaximumSize(QSize(16777215, 40));
        loginMessage->setBaseSize(QSize(0, 0));
        loginMessage->setFrameShape(QFrame::NoFrame);
        loginMessage->setAlignment(Qt::AlignCenter);
        loginMessage->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, loginMessage);


        gridLayout->addLayout(formLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        PWManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PWManagerClass);
        statusBar->setObjectName("statusBar");
        PWManagerClass->setStatusBar(statusBar);

        retranslateUi(PWManagerClass);

        QMetaObject::connectSlotsByName(PWManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PWManagerClass)
    {
        PWManagerClass->setWindowTitle(QCoreApplication::translate("PWManagerClass", "PWManager", nullptr));
        usernameLabel->setText(QCoreApplication::translate("PWManagerClass", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("PWManagerClass", "Password: ", nullptr));
        login->setText(QCoreApplication::translate("PWManagerClass", "Login", nullptr));
        loginMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PWManagerClass: public Ui_PWManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWMANAGER_H
