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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *view2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *resetSignUp;
    QPushButton *chessSignUp;
    QPushButton *checkersSignUp;
    QGridLayout *gridLayout_3;
    QLineEdit *spassword;
    QLabel *label;
    QLineEdit *susername;
    QLabel *label_2;
    QPushButton *signup;
    QWidget *Page0;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *view;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *resetLogin;
    QPushButton *chessLogin;
    QPushButton *checkersLogin;
    QGridLayout *gridLayout_5;
    QLineEdit *password;
    QLineEdit *username;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QPushButton *login;
    QSpacerItem *verticalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer;
    QLabel *loginMessage;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PWManagerClass)
    {
        if (PWManagerClass->objectName().isEmpty())
            PWManagerClass->setObjectName("PWManagerClass");
        PWManagerClass->resize(858, 704);
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font.setPointSize(12);
        PWManagerClass->setFont(font);
        PWManagerClass->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: rgb(35, 35, 35)\n"
"}\n"
"\n"
"QToolButton\n"
"{\n"
"	color: #FFF;\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border: 2px solid rgb(37, 39, 48);\n"
"	color: #FFF;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"	padding-top: 5px;\n"
"	padding-bottom: 5px;\n"
"	background-color: rgb(34, 36, 44);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QLineEdit:hover\n"
"{\n"
"	border: 2px solid rgb(48, 50, 62);\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border: 2px solid rgb(85, 170, 255);\n"
"	background-color: rgb(43,45,56);\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	color: #FFF\n"
"}\n"
"\n"
"QGraphicsView{\n"
"	border: none;\n"
"}"));
        actionSignUp = new QAction(PWManagerClass);
        actionSignUp->setObjectName("actionSignUp");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font1.setPointSize(11);
        actionSignUp->setFont(font1);
        actionSignUp->setMenuRole(QAction::NoRole);
        actionLogIn = new QAction(PWManagerClass);
        actionLogIn->setObjectName("actionLogIn");
        actionLogIn->setFont(font1);
        actionLogIn->setMenuRole(QAction::NoRole);
        actionpwvisible = new QAction(PWManagerClass);
        actionpwvisible->setObjectName("actionpwvisible");
        actionpwvisible->setCheckable(true);
        actionpwvisible->setMenuRole(QAction::NoRole);
        centralWidget = new QWidget(PWManagerClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(25, 25, 25)\n"
"}"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(9, -1, -1, -1);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(700, 500));
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        horizontalLayout_2 = new QHBoxLayout(Page1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        view2 = new QGraphicsView(Page1);
        view2->setObjectName("view2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(view2->sizePolicy().hasHeightForWidth());
        view2->setSizePolicy(sizePolicy);
        view2->setMinimumSize(QSize(480, 400));

        verticalLayout_2->addWidget(view2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        resetSignUp = new QPushButton(Page1);
        resetSignUp->setObjectName("resetSignUp");
        sizePolicy.setHeightForWidth(resetSignUp->sizePolicy().hasHeightForWidth());
        resetSignUp->setSizePolicy(sizePolicy);
        resetSignUp->setMinimumSize(QSize(100, 0));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        resetSignUp->setFont(font2);
        resetSignUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_4->addWidget(resetSignUp);

        chessSignUp = new QPushButton(Page1);
        chessSignUp->setObjectName("chessSignUp");
        sizePolicy.setHeightForWidth(chessSignUp->sizePolicy().hasHeightForWidth());
        chessSignUp->setSizePolicy(sizePolicy);
        chessSignUp->setMinimumSize(QSize(100, 0));
        chessSignUp->setFont(font2);
        chessSignUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_4->addWidget(chessSignUp);

        checkersSignUp = new QPushButton(Page1);
        checkersSignUp->setObjectName("checkersSignUp");
        sizePolicy.setHeightForWidth(checkersSignUp->sizePolicy().hasHeightForWidth());
        checkersSignUp->setSizePolicy(sizePolicy);
        checkersSignUp->setMinimumSize(QSize(100, 0));
        checkersSignUp->setFont(font2);
        checkersSignUp->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_4->addWidget(checkersSignUp);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName("gridLayout_3");
        spassword = new QLineEdit(Page1);
        spassword->setObjectName("spassword");
        sizePolicy.setHeightForWidth(spassword->sizePolicy().hasHeightForWidth());
        spassword->setSizePolicy(sizePolicy);
        spassword->setFont(font);
        spassword->setEchoMode(QLineEdit::Password);
        spassword->setClearButtonEnabled(false);

        gridLayout_3->addWidget(spassword, 3, 0, 1, 1);

        label = new QLabel(Page1);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        susername = new QLineEdit(Page1);
        susername->setObjectName("susername");
        sizePolicy.setHeightForWidth(susername->sizePolicy().hasHeightForWidth());
        susername->setSizePolicy(sizePolicy);
        susername->setFont(font);

        gridLayout_3->addWidget(susername, 1, 0, 1, 1);

        label_2 = new QLabel(Page1);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        signup = new QPushButton(Page1);
        signup->setObjectName("signup");
        signup->setFont(font);
        signup->setCursor(QCursor(Qt::PointingHandCursor));
        signup->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: #0d6efd;\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #0055ff;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        gridLayout_3->addWidget(signup, 4, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        stackedWidget->addWidget(Page1);
        Page0 = new QWidget();
        Page0->setObjectName("Page0");
        horizontalLayout = new QHBoxLayout(Page0);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        view = new QGraphicsView(Page0);
        view->setObjectName("view");
        sizePolicy.setHeightForWidth(view->sizePolicy().hasHeightForWidth());
        view->setSizePolicy(sizePolicy);
        view->setMinimumSize(QSize(480, 400));
        view->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(view);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        resetLogin = new QPushButton(Page0);
        resetLogin->setObjectName("resetLogin");
        sizePolicy.setHeightForWidth(resetLogin->sizePolicy().hasHeightForWidth());
        resetLogin->setSizePolicy(sizePolicy);
        resetLogin->setMinimumSize(QSize(100, 0));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font3.setPointSize(9);
        resetLogin->setFont(font3);
        resetLogin->setCursor(QCursor(Qt::PointingHandCursor));
        resetLogin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_3->addWidget(resetLogin);

        chessLogin = new QPushButton(Page0);
        chessLogin->setObjectName("chessLogin");
        sizePolicy.setHeightForWidth(chessLogin->sizePolicy().hasHeightForWidth());
        chessLogin->setSizePolicy(sizePolicy);
        chessLogin->setMinimumSize(QSize(100, 0));
        chessLogin->setFont(font2);
        chessLogin->setCursor(QCursor(Qt::PointingHandCursor));
        chessLogin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_3->addWidget(chessLogin);

        checkersLogin = new QPushButton(Page0);
        checkersLogin->setObjectName("checkersLogin");
        sizePolicy.setHeightForWidth(checkersLogin->sizePolicy().hasHeightForWidth());
        checkersLogin->setSizePolicy(sizePolicy);
        checkersLogin->setMinimumSize(QSize(100, 0));
        checkersLogin->setFont(font2);
        checkersLogin->setCursor(QCursor(Qt::PointingHandCursor));
        checkersLogin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: rgb(160, 76, 255);\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(170, 51, 255);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));

        horizontalLayout_3->addWidget(checkersLogin);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName("gridLayout_5");
        password = new QLineEdit(Page0);
        password->setObjectName("password");
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setFont(font);
        password->setStyleSheet(QString::fromUtf8(""));
        password->setEchoMode(QLineEdit::Password);
        password->setClearButtonEnabled(false);

        gridLayout_5->addWidget(password, 3, 0, 1, 1);

        username = new QLineEdit(Page0);
        username->setObjectName("username");
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        username->setFont(font);
        username->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(username, 1, 0, 1, 1);

        usernameLabel = new QLabel(Page0);
        usernameLabel->setObjectName("usernameLabel");
        sizePolicy.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy);
        usernameLabel->setFont(font);
        usernameLabel->setStyleSheet(QString::fromUtf8(""));
        usernameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(usernameLabel, 0, 0, 1, 1);

        passwordLabel = new QLabel(Page0);
        passwordLabel->setObjectName("passwordLabel");
        sizePolicy.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy);
        passwordLabel->setFont(font);
        passwordLabel->setStyleSheet(QString::fromUtf8(""));
        passwordLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(passwordLabel, 2, 0, 1, 1);

        login = new QPushButton(Page0);
        login->setObjectName("login");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy1);
        login->setFont(font);
        login->setCursor(QCursor(Qt::PointingHandCursor));
        login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: #FFF;\n"
"	background-color: #0d6efd;\n"
"	border-radius: 5px;\n"
"	padding: 10px\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #0055ff;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	border: 4px solid #98c1fe;\n"
"}"));
        login->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(login, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        stackedWidget->addWidget(Page0);

        gridLayout->addWidget(stackedWidget, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        title = new QLabel(centralWidget);
        title->setObjectName("title");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font4.setPointSize(20);
        font4.setBold(true);
        title->setFont(font4);
        title->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: #FFF\n"
"}"));
        title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(title, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        loginMessage = new QLabel(centralWidget);
        loginMessage->setObjectName("loginMessage");
        sizePolicy.setHeightForWidth(loginMessage->sizePolicy().hasHeightForWidth());
        loginMessage->setSizePolicy(sizePolicy);
        loginMessage->setMinimumSize(QSize(250, 60));
        loginMessage->setMaximumSize(QSize(250, 60));
        loginMessage->setBaseSize(QSize(0, 0));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font5.setPointSize(10);
        loginMessage->setFont(font5);
        loginMessage->setStyleSheet(QString::fromUtf8("QLabel { color : red; }"));
        loginMessage->setFrameShape(QFrame::NoFrame);
        loginMessage->setAlignment(Qt::AlignCenter);
        loginMessage->setWordWrap(true);

        gridLayout->addWidget(loginMessage, 2, 1, 1, 1, Qt::AlignHCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        PWManagerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PWManagerClass);
        statusBar->setObjectName("statusBar");
        PWManagerClass->setStatusBar(statusBar);
        toolBar = new QToolBar(PWManagerClass);
        toolBar->setObjectName("toolBar");
        toolBar->setFont(font2);
        toolBar->setMovable(false);
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
        resetSignUp->setText(QCoreApplication::translate("PWManagerClass", "Reset", nullptr));
        chessSignUp->setText(QCoreApplication::translate("PWManagerClass", "Chess", nullptr));
        checkersSignUp->setText(QCoreApplication::translate("PWManagerClass", "Checkers", nullptr));
        spassword->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "Password", nullptr));
        label->setText(QCoreApplication::translate("PWManagerClass", "Username", nullptr));
        susername->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("PWManagerClass", "Password", nullptr));
        signup->setText(QCoreApplication::translate("PWManagerClass", "Sign Up", nullptr));
        resetLogin->setText(QCoreApplication::translate("PWManagerClass", "Reset", nullptr));
        chessLogin->setText(QCoreApplication::translate("PWManagerClass", "Chess", nullptr));
        checkersLogin->setText(QCoreApplication::translate("PWManagerClass", "Checkers", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "Password", nullptr));
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("PWManagerClass", "Username", nullptr));
        usernameLabel->setText(QCoreApplication::translate("PWManagerClass", "Username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("PWManagerClass", "Password", nullptr));
        login->setText(QCoreApplication::translate("PWManagerClass", "Login", nullptr));
        title->setText(QCoreApplication::translate("PWManagerClass", "Gamified Password Manager", nullptr));
        loginMessage->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("PWManagerClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PWManagerClass: public Ui_PWManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PWMANAGER_H
