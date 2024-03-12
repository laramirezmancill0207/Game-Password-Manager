/********************************************************************************
** Form generated from reading UI file 'mainpasswordmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPASSWORDMENU_H
#define UI_MAINPASSWORDMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpasswordmenuClass
{
public:
    QAction *actionPassword;
    QAction *actionGame_Password;
    QAction *actionSelected;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionReplace;
    QAction *actionAbout;
    QAction *actionDocumentation;
    QAction *actionGithub;
    QAction *actionUsername;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *accurl;
    QLineEdit *accemail;
    QLabel *label_3;
    QLineEdit *accapp;
    QLineEdit *accpassword;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *accusername;
    QPushButton *addAccount;
    QLabel *warning;
    QLabel *label_6;
    QWidget *Page2;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QMenu *menuDelete;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainpasswordmenuClass)
    {
        if (mainpasswordmenuClass->objectName().isEmpty())
            mainpasswordmenuClass->setObjectName("mainpasswordmenuClass");
        mainpasswordmenuClass->resize(793, 400);
        actionPassword = new QAction(mainpasswordmenuClass);
        actionPassword->setObjectName("actionPassword");
        actionGame_Password = new QAction(mainpasswordmenuClass);
        actionGame_Password->setObjectName("actionGame_Password");
        actionSelected = new QAction(mainpasswordmenuClass);
        actionSelected->setObjectName("actionSelected");
        actionCopy = new QAction(mainpasswordmenuClass);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(mainpasswordmenuClass);
        actionPaste->setObjectName("actionPaste");
        actionFind = new QAction(mainpasswordmenuClass);
        actionFind->setObjectName("actionFind");
        actionFind_Next = new QAction(mainpasswordmenuClass);
        actionFind_Next->setObjectName("actionFind_Next");
        actionReplace = new QAction(mainpasswordmenuClass);
        actionReplace->setObjectName("actionReplace");
        actionAbout = new QAction(mainpasswordmenuClass);
        actionAbout->setObjectName("actionAbout");
        actionDocumentation = new QAction(mainpasswordmenuClass);
        actionDocumentation->setObjectName("actionDocumentation");
        actionGithub = new QAction(mainpasswordmenuClass);
        actionGithub->setObjectName("actionGithub");
        actionUsername = new QAction(mainpasswordmenuClass);
        actionUsername->setObjectName("actionUsername");
        actionUsername->setEnabled(false);
        actionUsername->setMenuRole(QAction::NoRole);
        centralWidget = new QWidget(mainpasswordmenuClass);
        centralWidget->setObjectName("centralWidget");
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        horizontalLayout = new QHBoxLayout(Page1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(Page1);
        label_2->setObjectName("label_2");
        QFont font;
        font.setBold(true);
        label_2->setFont(font);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1, Qt::AlignHCenter);

        label_5 = new QLabel(Page1);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout_4->addWidget(label_5, 2, 2, 1, 1, Qt::AlignHCenter);

        accurl = new QLineEdit(Page1);
        accurl->setObjectName("accurl");

        gridLayout_4->addWidget(accurl, 2, 1, 1, 1);

        accemail = new QLineEdit(Page1);
        accemail->setObjectName("accemail");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accemail->sizePolicy().hasHeightForWidth());
        accemail->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(accemail, 0, 1, 1, 1);

        label_3 = new QLabel(Page1);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout_4->addWidget(label_3, 1, 1, 1, 1, Qt::AlignHCenter);

        accapp = new QLineEdit(Page1);
        accapp->setObjectName("accapp");

        gridLayout_4->addWidget(accapp, 2, 3, 1, 1);

        accpassword = new QLineEdit(Page1);
        accpassword->setObjectName("accpassword");

        gridLayout_4->addWidget(accpassword, 1, 2, 1, 1);

        label = new QLabel(Page1);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout_4->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(Page1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1, Qt::AlignHCenter);

        accusername = new QLineEdit(Page1);
        accusername->setObjectName("accusername");

        gridLayout_4->addWidget(accusername, 0, 3, 1, 1);

        addAccount = new QPushButton(Page1);
        addAccount->setObjectName("addAccount");

        gridLayout_4->addWidget(addAccount, 3, 2, 1, 1);

        warning = new QLabel(Page1);
        warning->setObjectName("warning");
        warning->setAlignment(Qt::AlignCenter);
        warning->setWordWrap(false);

        gridLayout_4->addWidget(warning, 3, 1, 1, 1);

        label_6 = new QLabel(Page1);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        stackedWidget->addWidget(Page1);
        Page2 = new QWidget();
        Page2->setObjectName("Page2");
        stackedWidget->addWidget(Page2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setMinimumSize(QSize(450, 0));
        tableView->setStyleSheet(QString::fromUtf8("QTableView::item:alternate { background-color: #bfffbf; } \n"
"QTableView::item { background-color: #deffde;}\n"
"QTableView::item:selected{ background-color: #000000;}"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setDefaultSectionSize(150);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableView, 0, 1, 1, 1);

        mainpasswordmenuClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainpasswordmenuClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 793, 22));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName("menuNew");
        menuDelete = new QMenu(menuBar);
        menuDelete->setObjectName("menuDelete");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        mainpasswordmenuClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainpasswordmenuClass);
        mainToolBar->setObjectName("mainToolBar");
        mainpasswordmenuClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainpasswordmenuClass);
        statusBar->setObjectName("statusBar");
        mainpasswordmenuClass->setStatusBar(statusBar);

        menuBar->addAction(menuNew->menuAction());
        menuBar->addAction(menuDelete->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuNew->addAction(actionPassword);
        menuNew->addAction(actionGame_Password);
        menuDelete->addAction(actionSelected);
        menuDelete->addAction(actionCopy);
        menuDelete->addAction(actionPaste);
        menuDelete->addAction(actionFind);
        menuDelete->addAction(actionFind_Next);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionGithub);
        mainToolBar->addAction(actionUsername);

        retranslateUi(mainpasswordmenuClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainpasswordmenuClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainpasswordmenuClass)
    {
        mainpasswordmenuClass->setWindowTitle(QCoreApplication::translate("mainpasswordmenuClass", "mainpasswordmenu", nullptr));
        actionPassword->setText(QCoreApplication::translate("mainpasswordmenuClass", "Password", nullptr));
        actionGame_Password->setText(QCoreApplication::translate("mainpasswordmenuClass", "Game Password", nullptr));
        actionSelected->setText(QCoreApplication::translate("mainpasswordmenuClass", "Cut", nullptr));
        actionCopy->setText(QCoreApplication::translate("mainpasswordmenuClass", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("mainpasswordmenuClass", "Paste", nullptr));
        actionFind->setText(QCoreApplication::translate("mainpasswordmenuClass", "Find", nullptr));
        actionFind_Next->setText(QCoreApplication::translate("mainpasswordmenuClass", "Find Next", nullptr));
        actionReplace->setText(QCoreApplication::translate("mainpasswordmenuClass", "Replace", nullptr));
        actionAbout->setText(QCoreApplication::translate("mainpasswordmenuClass", "About", nullptr));
        actionDocumentation->setText(QCoreApplication::translate("mainpasswordmenuClass", "Documentation", nullptr));
        actionGithub->setText(QCoreApplication::translate("mainpasswordmenuClass", "Github", nullptr));
        actionUsername->setText(QCoreApplication::translate("mainpasswordmenuClass", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("mainpasswordmenuClass", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("mainpasswordmenuClass", "Application", nullptr));
        label_3->setText(QCoreApplication::translate("mainpasswordmenuClass", "Password", nullptr));
        label->setText(QCoreApplication::translate("mainpasswordmenuClass", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("mainpasswordmenuClass", "URL", nullptr));
        addAccount->setText(QCoreApplication::translate("mainpasswordmenuClass", "Add Account", nullptr));
        warning->setText(QString());
        label_6->setText(QString());
        menuNew->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "New", nullptr));
        menuDelete->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpasswordmenuClass: public Ui_mainpasswordmenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPASSWORDMENU_H
