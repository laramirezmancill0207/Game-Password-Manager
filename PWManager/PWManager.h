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

private:
    Ui::PWManagerClass ui;
};
