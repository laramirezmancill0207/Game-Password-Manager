#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PWManager.h"
#include "mainpasswordmenu.h"

class PWManager : public QMainWindow
{
    Q_OBJECT

public:
    PWManager(QWidget *parent = nullptr);
    ~PWManager();

private slots:
    void visible(QLineEdit* pwField);
    void invisible(QLineEdit* pwField);
    void on_login_clicked();
    void on_signup_clicked();
    void on_actionSignUp_triggered();
    void on_actionLogIn_triggered();

private:
    Ui::PWManagerClass ui;
    mainpasswordmenu* window;
};
