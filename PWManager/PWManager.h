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

    std::string getHash();
    void setHash(std::string hash);

private slots:
    void visible(QLineEdit* pwField);
    void invisible(QLineEdit* pwField);
    void on_login_clicked();
    void on_signup_clicked();
    void on_actionSignUp_triggered();
    void on_actionLogIn_triggered();
    void on_reset_clicked();
    void on_chess_clicked();
    void on_checkers_clicked();

private:
    Ui::PWManagerClass ui;
    mainpasswordmenu* window;
    std::string gameHash;
};
