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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PWManagerClass
{
public:
    QAction *actionSignUp;
    QAction *actionLogIn;
    QAction *actionpwvisible;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *loginMessage;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *title;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QGridLayout *gridLayout_3;
    QPushButton *signup;
    QLineEdit *spassword;
    QLineEdit *susername;
    QLabel *label;
    QLabel *label_2;
    QWidget *Page0;
    QGridLayout *gridLayout_2;
    QPushButton *login;
    QLineEdit *username;
    QLabel *usernameLabel;
    QLineEdit *password;
    QLabel *passwordLabel;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PWManagerClass)
    {
        if (PWManagerClass->objectName().isEmpty())
            PWManagerClass->setObjectName("PWManagerClass");
        PWManagerClass->resize(805, 683);
        actionSignUp = new QAction(PWManagerClass);
        actionSignUp->setObjectName("actionSignUp");
        actionSignUp->setMenuRole(QAction::NoRole);
        actionLogIn = new QAction(PWManagerClass);
        actionLogIn->setObjectName("actionLogIn");
        actionLogIn->setMenuRole(QAction::NoRole);
        actionpwvisible = new QAction(PWManagerClass);
        actionpwvisible->setObjectName("actionpwvisible");
        actionpwvisible->setCheckable(true);
        actionpwvisible->setMenuRole(QAction::NoRole);
        centralWidget = new QWidget(PWManagerClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(9, -1, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        loginMessage = new QLabel(centralWidget);
        loginMessage->setObjectName("loginMessage");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginMessage->sizePolicy().hasHeightForWidth());
        loginMessage->setSizePolicy(sizePolicy);
        loginMessage->setMinimumSize(QSize(250, 60));
        loginMessage->setMaximumSize(QSize(250, 60));
        loginMessage->setBaseSize(QSize(0, 0));
        loginMessage->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));
        loginMessage->setFrameShape(QFrame::NoFrame);
        loginMessage->setAlignment(Qt::AlignCenter);
        loginMessage->setWordWrap(true);

        gridLayout->addWidget(loginMessage, 3, 1, 1, 1, Qt::AlignHCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        title = new QLabel(centralWidget);
        title->setObjectName("title");
        QFont font;
        font.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font.setPointSize(20);
        font.setBold(true);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 1, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        gridLayout_3 = new QGridLayout(Page1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName("gridLayout_3");
        signup = new QPushButton(Page1);
        signup->setObjectName("signup");

        gridLayout_3->addWidget(signup, 2, 1, 1, 1);

        spassword = new QLineEdit(Page1);
        spassword->setObjectName("spassword");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spassword->sizePolicy().hasHeightForWidth());
        spassword->setSizePolicy(sizePolicy1);
        spassword->setEchoMode(QLineEdit::Password);
        spassword->setClearButtonEnabled(false);

        gridLayout_3->addWidget(spassword, 1, 1, 1, 1);

        susername = new QLineEdit(Page1);
        susername->setObjectName("susername");
        sizePolicy1.setHeightForWidth(susername->sizePolicy().hasHeightForWidth());
        susername->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(susername, 0, 1, 1, 1);

        label = new QLabel(Page1);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(Page1);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        stackedWidget->addWidget(Page1);
        Page0 = new QWidget();
        Page0->setObjectName("Page0");
        gridLayout_2 = new QGridLayout(Page0);
        gridLayout_2->setSpacing(100);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_2->setContentsMargins(175, 100, 175, 100);
        login = new QPushButton(Page0);
        login->setObjectName("login");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy2);
        login->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(login, 3, 2, 1, 1);

        username = new QLineEdit(Page0);
        username->setObjectName("username");
        sizePolicy1.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(username, 1, 2, 1, 1);

        usernameLabel = new QLabel(Page0);
        usernameLabel->setObjectName("usernameLabel");
        sizePolicy.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(usernameLabel, 1, 1, 1, 1);

        password = new QLineEdit(Page0);
        password->setObjectName("password");
        sizePolicy1.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy1);
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(false);

        gridLayout_2->addWidget(password, 2, 2, 1, 1);

        passwordLabel = new QLabel(Page0);
        passwordLabel->setObjectName("passwordLabel");
        sizePolicy.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(passwordLabel, 2, 1, 1, 1);

        stackedWidget->addWidget(Page0);

        gridLayout->addWidget(stackedWidget, 4, 1, 1, 1);

        PWManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PWManagerClass);
        statusBar->setObjectName("statusBar");
        PWManagerClass->setStatusBar(statusBar);
        toolBar = new QToolBar(PWManagerClass);
        toolBar->setObjectName("toolBar");
        PWManagerClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionLogIn);
        toolBar->addAction(actionSignUp);

        retranslateUi(PWManagerClass);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PWManagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PWManagerClass)
    {
        PWManagerClass->setWindowTitle(QCoreApplication::translate("PWManagerClass", "Password Manager", nullptr));
        actionSignUp->setText(QCoreApplication::translate("PWManagerClass", "Sign Up", nullptr));
        actionLogIn->setText(QCoreApplication::translate("PWManagerClass", "Log In", nullptr));
        actionpwvisible->setText(QCoreApplication::translate("PWManagerClass", "pwvisible", nullptr));
        loginMessage->setText(QString());
        title->setText(QCoreApplication::translate("PWManagerClass", "Gamified Password Manager", nullptr));
        signup->setText(QCoreApplication::translate("PWManagerClass", "Sign Up", nullptr));
        spassword->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "password", nullptr));
        susername->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "username", nullptr));
        label->setText(QCoreApplication::translate("PWManagerClass", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("PWManagerClass", "Password:", nullptr));
        login->setText(QCoreApplication::translate("PWManagerClass", "Login", nullptr));
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "username", nullptr));
        usernameLabel->setText(QCoreApplication::translate("PWManagerClass", "Username:", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "password", nullptr));
        passwordLabel->setText(QCoreApplication::translate("PWManagerClass", "Password: ", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("PWManagerClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PWManagerClass: public Ui_PWManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWMANAGER_H
