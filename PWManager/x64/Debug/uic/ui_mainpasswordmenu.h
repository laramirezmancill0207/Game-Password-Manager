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
#include <QtOpenGLWidgets/QOpenGLWidget>
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
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QPushButton *homeMenu;
    QPushButton *gameMenu;
    QPushButton *settingsMenu;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchBar;
    QLabel *label_8;
    QPushButton *deleteAccount;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *warning;
    QLabel *label_3;
    QPushButton *addAccount;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *accusername;
    QLabel *label_2;
    QLineEdit *accpassword;
    QLineEdit *accurl;
    QLineEdit *accapp;
    QLineEdit *accemail;
    QLabel *label_6;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QWidget *Page2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_7;
    QOpenGLWidget *openGLWidget;
    QWidget *Page3;
    QMenuBar *menuBar;
    QMenu *menuNew;
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
"	background-color: #bfffbf;\n"
"} \n"
"QTableView::item \n"
"{ \n"
"	background-color: #deffde;\n"
"	padding: 40px;\n"
"}\n"
"QTableView::item:selected\n"
"{ \n"
"	background-color: #000000;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"	background-color: rgb(138, 1"
                        "38, 138);\n"
"	border: none;\n"
"	color: white;\n"
"	font-weight: bold;\n"
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
        actionAdd_Menu = new QAction(mainpasswordmenuClass);
        actionAdd_Menu->setObjectName("actionAdd_Menu");
        actionAdd_Menu->setCheckable(true);
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
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(250, 0));
        widget->setStyleSheet(QString::fromUtf8("QWidget\n"
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
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(2, 9, 2, -1);
        label_7 = new QLabel(widget);
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

        homeMenu = new QPushButton(widget);
        homeMenu->setObjectName("homeMenu");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font1.setPointSize(12);
        homeMenu->setFont(font1);
        homeMenu->setCursor(QCursor(Qt::PointingHandCursor));
        homeMenu->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(homeMenu);

        gameMenu = new QPushButton(widget);
        gameMenu->setObjectName("gameMenu");
        gameMenu->setFont(font1);
        gameMenu->setCursor(QCursor(Qt::PointingHandCursor));
        gameMenu->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(gameMenu);

        settingsMenu = new QPushButton(widget);
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


        horizontalLayout_4->addWidget(widget);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        Page1->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Page1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame_3 = new QFrame(Page1);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        searchBar = new QLineEdit(frame_3);
        searchBar->setObjectName("searchBar");
        searchBar->setFont(font1);

        horizontalLayout->addWidget(searchBar);


        verticalLayout_2->addWidget(frame_3);

        label_8 = new QLabel(Page1);
        label_8->setObjectName("label_8");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: grey;\n"
"}"));

        verticalLayout_2->addWidget(label_8);

        deleteAccount = new QPushButton(Page1);
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

        verticalLayout_2->addWidget(deleteAccount);

        widget_2 = new QWidget(Page1);
        widget_2->setObjectName("widget_2");
        horizontalLayout_5 = new QHBoxLayout(widget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName("gridLayout_4");
        warning = new QLabel(frame);
        warning->setObjectName("warning");
        warning->setAlignment(Qt::AlignCenter);
        warning->setWordWrap(false);

        gridLayout_4->addWidget(warning, 3, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font3.setPointSize(11);
        font3.setBold(true);
        label_3->setFont(font3);

        gridLayout_4->addWidget(label_3, 1, 1, 1, 1, Qt::AlignHCenter);

        addAccount = new QPushButton(frame);
        addAccount->setObjectName("addAccount");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font4.setPointSize(11);
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

        gridLayout_4->addWidget(addAccount, 3, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName("label");
        label->setFont(font3);

        gridLayout_4->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter);

        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font5.setPointSize(12);
        font5.setBold(true);
        label_4->setFont(font5);

        gridLayout_4->addWidget(label_4, 2, 0, 1, 1, Qt::AlignHCenter);

        accusername = new QLineEdit(frame);
        accusername->setObjectName("accusername");
        accusername->setFont(font2);

        gridLayout_4->addWidget(accusername, 0, 3, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setFont(font3);

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1, Qt::AlignHCenter);

        accpassword = new QLineEdit(frame);
        accpassword->setObjectName("accpassword");
        accpassword->setFont(font2);

        gridLayout_4->addWidget(accpassword, 1, 2, 1, 1);

        accurl = new QLineEdit(frame);
        accurl->setObjectName("accurl");
        accurl->setFont(font2);

        gridLayout_4->addWidget(accurl, 2, 1, 1, 1);

        accapp = new QLineEdit(frame);
        accapp->setObjectName("accapp");
        accapp->setFont(font2);

        gridLayout_4->addWidget(accapp, 2, 3, 1, 1);

        accemail = new QLineEdit(frame);
        accemail->setObjectName("accemail");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(accemail->sizePolicy().hasHeightForWidth());
        accemail->setSizePolicy(sizePolicy3);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font6.setPointSize(9);
        accemail->setFont(font6);

        gridLayout_4->addWidget(accemail, 0, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setFont(font3);
        label_5->setFrameShape(QFrame::NoFrame);

        gridLayout_4->addWidget(label_5, 2, 2, 1, 1, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(gridLayout_4);


        horizontalLayout_5->addWidget(frame);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        tableView = new QTableView(frame_2);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy4);
        tableView->setMinimumSize(QSize(0, 0));
        tableView->setFont(font6);
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


        horizontalLayout_5->addWidget(frame_2);


        verticalLayout_2->addWidget(widget_2);

        stackedWidget->addWidget(Page1);
        Page2 = new QWidget();
        Page2->setObjectName("Page2");
        verticalLayout_3 = new QVBoxLayout(Page2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_4 = new QFrame(Page2);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        openGLWidget = new QOpenGLWidget(frame_4);
        openGLWidget->setObjectName("openGLWidget");

        horizontalLayout_7->addWidget(openGLWidget);


        verticalLayout_3->addWidget(frame_4);

        stackedWidget->addWidget(Page2);
        Page3 = new QWidget();
        Page3->setObjectName("Page3");
        stackedWidget->addWidget(Page3);

        horizontalLayout_4->addWidget(stackedWidget);

        mainpasswordmenuClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainpasswordmenuClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1149, 22));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName("menuNew");
        menuDelete = new QMenu(menuBar);
        menuDelete->setObjectName("menuDelete");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName("menuWindow");
        mainpasswordmenuClass->setMenuBar(menuBar);

        menuBar->addAction(menuNew->menuAction());
        menuBar->addAction(menuDelete->menuAction());
        menuBar->addAction(menuWindow->menuAction());
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
        warning->setText(QString());
        label_3->setText(QCoreApplication::translate("mainpasswordmenuClass", "Password", nullptr));
        addAccount->setText(QCoreApplication::translate("mainpasswordmenuClass", "Add Account", nullptr));
        label->setText(QCoreApplication::translate("mainpasswordmenuClass", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("mainpasswordmenuClass", "URL", nullptr));
        label_2->setText(QCoreApplication::translate("mainpasswordmenuClass", "Username", nullptr));
        label_6->setText(QString());
        label_5->setText(QCoreApplication::translate("mainpasswordmenuClass", "Application", nullptr));
        menuNew->setTitle(QCoreApplication::translate("mainpasswordmenuClass", "New", nullptr));
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
