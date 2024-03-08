#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PWManager.h"

class PWManager : public QMainWindow
{
    Q_OBJECT

public:
    PWManager(QWidget *parent = nullptr);
    ~PWManager();

private slots:
    void on_login_clicked();
    void on_signup_clicked();
    void on_switchs_clicked();
    void on_switchl_clicked();

private:
    Ui::PWManagerClass ui;
};
