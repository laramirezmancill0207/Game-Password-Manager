#include "PWManager.h"
#include "login.h"
#include <string>

PWManager::PWManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

void PWManager::on_login_clicked()
{
    std::string textUser;
    std::string textPass;



    textUser = ui.username->text().toStdString();
    textPass = ui.password->text().toStdString();

    if (passwordManager::checkMasterLogin(textUser, textPass))
    {
        ui.loginMessage->setText("login successful");
        return;
    }

    ui.loginMessage->setText("Either username or password is incorrect");
}

PWManager::~PWManager()
{}
