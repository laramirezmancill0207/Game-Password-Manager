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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gameopengl.h"

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
    QAction *actionDelete_Menu;
    QAction *actionAdd_Menu;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *dashboardWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QPushButton *homeMenu;
    QPushButton *gameMenu;
    QPushButton *settingsMenu;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QVBoxLayout *verticalLayout_2;
    QFrame *searchFrame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchBar;
    QWidget *deleteWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QPushButton *deleteAccount;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QFrame *addFrame;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *accusername;
    QLineEdit *accapp;
    QLabel *label_4;
    QPushButton *addAccount;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *accemail;
    QLineEdit *accpassword;
    QLineEdit *accurl;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QFrame *tableFrame;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QWidget *Page2;
    QVBoxLayout *verticalLayout_3;
    QFrame *gameWidget;
    QHBoxLayout *horizontalLayout_7;
    GameOpenGL *openGLWidget;
    QWidget *Page3;
    QMenuBar *menuB;
    QMenu *menuDelete;
    QMenu *menuHelp;
    QMenu *menuWindow;

    void setupUi(QMainWindow *mainpasswordmenuClass)
    {
        if (mainpasswordmenuClass->objectName().isEmpty())
            mainpasswordmenuClass->setObjectName("mainpasswordmenuClass");
        mainpasswordmenuClass->resize(1149, 491);
        mainpasswordmenuClass->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"	background-color: rgb(35, 35, 35)\n"
"}\n"
"\n"
".QFrame\n"
"{\n"
"	border: 2px solid rgb(255, 255, 255);\n"
"	border-radius: 20px;\n"
"}\n"
"\n"
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
"QTableView::item:alternate \n"
"{ \n"
"	background-color: rgb(36, 36, 36);\n"
"} \n"
"QTableView::item \n"
"{ \n"
"	background-color: rgb(25, 25, 25);\n"
"	color: white;\n"
"	padding: 40px;\n"
"}\n"
"QTableView::item:selected\n"
"{ \n"
"	background-color: rgb(0, 44, 131);\n"
"}\n"
"\n"
"QHeaderView::sect"
                        "ion\n"
"{\n"
"	background-color: rgb(138, 138, 138);\n"
"	border: none;\n"
"	border-radius: 10px;\n"
"	color: white;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"	border: none;\n"
"}"));
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
        actionDelete_Menu = new QAction(mainpasswordmenuClass);
        actionDelete_Menu->setObjectName("actionDelete_Menu");
        actionDelete_Menu->setCheckable(true);
        actionDelete_Menu->setChecked(true);
        actionAdd_Menu = new QAction(mainpasswordmenuClass);
        actionAdd_Menu->setObjectName("actionAdd_Menu");
        actionAdd_Menu->setCheckable(true);
        actionAdd_Menu->setChecked(true);
        centralWidget = new QWidget(mainpasswordmenuClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(25, 25, 25)\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        dashboardWidget = new QWidget(centralWidget);
        dashboardWidget->setObjectName("dashboardWidget");
        dashboardWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dashboardWidget->sizePolicy().hasHeightForWidth());
        dashboardWidget->setSizePolicy(sizePolicy);
        dashboardWidget->setMinimumSize(QSize(250, 0));
        dashboardWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: rgb(113, 134, 184);\n"
"}\n"
"\n"
".QWidget\n"
"{\n"
"	border: 2px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"\n"
"QPushButton\n"
"{\n"
"	border: none;\n"
"	color: black;\n"
"}"));
        verticalLayout = new QVBoxLayout(dashboardWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(2, 9, 2, -1);
        label_7 = new QLabel(dashboardWidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font.setPointSize(18);
        font.setBold(true);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        homeMenu = new QPushButton(dashboardWidget);
        homeMenu->setObjectName("homeMenu");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font1.setPointSize(12);
        homeMenu->setFont(font1);
        homeMenu->setCursor(QCursor(Qt::PointingHandCursor));
        homeMenu->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(homeMenu);

        gameMenu = new QPushButton(dashboardWidget);
        gameMenu->setObjectName("gameMenu");
        gameMenu->setFont(font1);
        gameMenu->setCursor(QCursor(Qt::PointingHandCursor));
        gameMenu->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(gameMenu);

        settingsMenu = new QPushButton(dashboardWidget);
        settingsMenu->setObjectName("settingsMenu");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(settingsMenu->sizePolicy().hasHeightForWidth());
        settingsMenu->setSizePolicy(sizePolicy2);
        settingsMenu->setFont(font1);
        settingsMenu->setCursor(QCursor(Qt::PointingHandCursor));
        settingsMenu->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(settingsMenu);


        horizontalLayout_4->addWidget(dashboardWidget);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        Page1->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Page1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        searchFrame = new QFrame(Page1);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setFrameShape(QFrame::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(searchFrame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        searchBar = new QLineEdit(searchFrame);
        searchBar->setObjectName("searchBar");
        searchBar->setFont(font1);

        horizontalLayout->addWidget(searchBar);


        verticalLayout_2->addWidget(searchFrame);

        deleteWidget = new QWidget(Page1);
        deleteWidget->setObjectName("deleteWidget");
        verticalLayout_4 = new QVBoxLayout(deleteWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(deleteWidget);
        label_8->setObjectName("label_8");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: grey;\n"
"}"));

        verticalLayout_4->addWidget(label_8);

        deleteAccount = new QPushButton(deleteWidget);
        deleteAccount->setObjectName("deleteAccount");
        deleteAccount->setFont(font1);
        deleteAccount->setCursor(QCursor(Qt::PointingHandCursor));
        deleteAccount->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        verticalLayout_4->addWidget(deleteAccount);


        verticalLayout_2->addWidget(deleteWidget);

        widget_2 = new QWidget(Page1);
        widget_2->setObjectName("widget_2");
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addFrame = new QFrame(widget_2);
        addFrame->setObjectName("addFrame");
        addFrame->setStyleSheet(QString::fromUtf8(""));
        addFrame->setFrameShape(QFrame::StyledPanel);
        addFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(addFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(addFrame);
        label_2->setObjectName("label_2");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font3.setPointSize(11);
        font3.setBold(true);
        label_2->setFont(font3);

        gridLayout_4->addWidget(label_2, 4, 0, 1, 1);

        label_5 = new QLabel(addFrame);
        label_5->setObjectName("label_5");
        label_5->setFont(font3);
        label_5->setFrameShape(QFrame::NoFrame);

        gridLayout_4->addWidget(label_5, 3, 0, 1, 1);

        accusername = new QLineEdit(addFrame);
        accusername->setObjectName("accusername");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font4.setPointSize(11);
        accusername->setFont(font4);

        gridLayout_4->addWidget(accusername, 4, 1, 1, 1);

        accapp = new QLineEdit(addFrame);
        accapp->setObjectName("accapp");
        accapp->setFont(font4);

        gridLayout_4->addWidget(accapp, 3, 1, 1, 1);

        label_4 = new QLabel(addFrame);
        label_4->setObjectName("label_4");
        label_4->setFont(font3);

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1, Qt::AlignHCenter);

        addAccount = new QPushButton(addFrame);
        addAccount->setObjectName("addAccount");
        addAccount->setFont(font4);
        addAccount->setCursor(QCursor(Qt::PointingHandCursor));
        addAccount->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        gridLayout_4->addWidget(addAccount, 5, 1, 1, 1);

        label_3 = new QLabel(addFrame);
        label_3->setObjectName("label_3");
        label_3->setFont(font3);

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(addFrame);
        label->setObjectName("label");
        label->setFont(font3);

        gridLayout_4->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        accemail = new QLineEdit(addFrame);
        accemail->setObjectName("accemail");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(accemail->sizePolicy().hasHeightForWidth());
        accemail->setSizePolicy(sizePolicy3);
        accemail->setFont(font4);

        gridLayout_4->addWidget(accemail, 0, 1, 1, 1);

        accpassword = new QLineEdit(addFrame);
        accpassword->setObjectName("accpassword");
        accpassword->setFont(font4);
        accpassword->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(accpassword, 1, 1, 1, 1);

        accurl = new QLineEdit(addFrame);
        accurl->setObjectName("accurl");
        accurl->setFont(font4);

        gridLayout_4->addWidget(accurl, 2, 1, 1, 1);

        label_6 = new QLabel(addFrame);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_4);


        horizontalLayout_5->addWidget(addFrame);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        tableFrame = new QFrame(widget_2);
        tableFrame->setObjectName("tableFrame");
        tableFrame->setFrameShape(QFrame::StyledPanel);
        tableFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(tableFrame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        tableView = new QTableView(tableFrame);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy4);
        tableView->setMinimumSize(QSize(0, 0));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font5.setPointSize(9);
        tableView->setFont(font5);
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setTextElideMode(Qt::ElideNone);
        tableView->setShowGrid(false);
        tableView->setWordWrap(true);
        tableView->horizontalHeader()->setMinimumSectionSize(20);
        tableView->horizontalHeader()->setDefaultSectionSize(150);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_3->addWidget(tableView);


        horizontalLayout_5->addWidget(tableFrame);


        verticalLayout_2->addWidget(widget_2);

        stackedWidget->addWidget(Page1);
        Page2 = new QWidget();
        Page2->setObjectName("Page2");
        verticalLayout_3 = new QVBoxLayout(Page2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gameWidget = new QFrame(Page2);
        gameWidget->setObjectName("gameWidget");
        gameWidget->setFrameShape(QFrame::StyledPanel);
        gameWidget->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(gameWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        openGLWidget = new GameOpenGL(gameWidget);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout_7->addWidget(openGLWidget);


        verticalLayout_3->addWidget(gameWidget);

        stackedWidget->addWidget(Page2);
        Page3 = new QWidget();
        Page3->setObjectName("Page3");
        stackedWidget->addWidget(Page3);

        horizontalLayout_4->addWidget(stackedWidget);

        mainpasswordmenuClass->setCentralWidget(centralWidget);
        menuB = new QMenuBar(mainpasswordmenuClass);
        menuB->setObjectName("menuB");
        menuB->setGeometry(QRect(0, 0, 1149, 22));
        menuDelete = new QMenu(menuB);
        menuDelete->setObjectName("menuDelete");
        menuHelp = new QMenu(menuB);
        menuHelp->setObjectName("menuHelp");
        menuWindow = new QMenu(menuB);
        menuWindow->setObjectName("menuWindow");
        mainpasswordmenuClass->setMenuBar(menuB);

        menuB->addAction(menuDelete->menuAction());
        menuB->addAction(menuWindow->menuAction());
        menuB->addAction(menuHelp->menuAction());
        menuDelete->addAction(actionSelected);
        menuDelete->addAction(actionCopy);
        menuDelete->addAction(actionPaste);
        menuDelete->addAction(actionFind);
        menuDelete->addAction(actionFind_Next);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionDocumentation);
        menuHelp->addAction(actionGithub);
        menuWindow->addAction(actionDelete_Menu);
        menuWindow->addAction(actionAdd_Menu);

        retranslateUi(mainpasswordmenuClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainpasswordmenuClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainpasswordmenuClass)
    {
        mainpasswordmenuClass->setWindowTitle(QCoreApplication::translate("mainpasswordmenuClass", "Gamified Password Manager", nullptr));
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
        actionDelete_Menu->setText(QCoreApplication::translate("mainpasswordmenuClass", "Delete Menu", nullptr));
        actionAdd_Menu->setText(QCoreApplication::translate("mainpasswordmenuClass", "Add Menu", nullptr));
        label_7->setText(QCoreApplication::translate("mainpasswordmenuClass", "Menu", nullptr));
        homeMenu->setText(QCoreApplication::translate("mainpasswordmenuClass", "Home", nullptr));
        gameMenu->setText(QCoreApplication::translate("mainpasswordmenuClass", "Game", nullptr));
        settingsMenu->setText(QCoreApplication::translate("mainpasswordmenuClass", "Settings", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "Search based on application name", nullptr));
        label_8->setText(QCoreApplication::translate("mainpasswordmenuClass", "Select full row to delete", nullptr));
        deleteAccount->setText(QCoreApplication::translate("mainpasswordmenuClass", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("mainpasswordmenuClass", "Username", nullptr));
        label_5->setText(QCoreApplication::translate("mainpasswordmenuClass", "Application", nullptr));
        accusername->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "Username", nullptr));
        accapp->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "Application", nullptr));
        label_4->setText(QCoreApplication::translate("mainpasswordmenuClass", "URL", nullptr));
        addAccount->setText(QCoreApplication::translate("mainpasswordmenuClass", "Add Account", nullptr));
        label_3->setText(QCoreApplication::translate("mainpasswordmenuClass", "Password", nullptr));
        label->setText(QCoreApplication::translate("mainpasswordmenuClass", "Email", nullptr));
        accemail->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "Email", nullptr));
        accpassword->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "Password", nullptr));
        accurl->setPlaceholderText(QCoreApplication::translate("mainpasswordmenuClass", "URL", nullptr));
        label_6->setText(QString());
        menuDelete->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "Help", nullptr));
        menuWindow->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpasswordmenuClass: public Ui_mainpasswordmenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPASSWORDMENU_H
