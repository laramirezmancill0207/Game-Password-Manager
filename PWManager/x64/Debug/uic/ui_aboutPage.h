/********************************************************************************
** Form generated from reading UI file 'aboutPage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTPAGE_H
#define UI_ABOUTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_aboutPageClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *aboutPageClass)
    {
        if (aboutPageClass->objectName().isEmpty())
            aboutPageClass->setObjectName("aboutPageClass");
        aboutPageClass->setWindowModality(Qt::ApplicationModal);
        aboutPageClass->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutPageClass->sizePolicy().hasHeightForWidth());
        aboutPageClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font.setBold(true);
        aboutPageClass->setFont(font);
        aboutPageClass->setSizeGripEnabled(false);
        aboutPageClass->setModal(true);
        label = new QLabel(aboutPageClass);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 351, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 0, 0);\n"
"}"));
        label_2 = new QLabel(aboutPageClass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 110, 551, 91));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Lucida Sans Unicode")});
        font2.setBold(false);
        label_2->setFont(font2);
        label_3 = new QLabel(aboutPageClass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 220, 461, 16));
        label_3->setFont(font2);

        retranslateUi(aboutPageClass);

        QMetaObject::connectSlotsByName(aboutPageClass);
    } // setupUi

    void retranslateUi(QDialog *aboutPageClass)
    {
        aboutPageClass->setWindowTitle(QCoreApplication::translate("aboutPageClass", "aboutPage", nullptr));
        label->setText(QCoreApplication::translate("aboutPageClass", "Gamified Password Manager", nullptr));
        label_2->setText(QCoreApplication::translate("aboutPageClass", "A password storage software which allows the use of various games to enter/create passwords", nullptr));
        label_3->setText(QCoreApplication::translate("aboutPageClass", "Github: https://github.com/laramirezmancill0207/Game-Password-Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutPageClass: public Ui_aboutPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTPAGE_H
