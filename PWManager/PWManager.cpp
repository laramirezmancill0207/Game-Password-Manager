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
    std::string textUser = ui.username->text().toStdString();
    std::string textPass = ui.password->text().toStdString();


    if (passwordManager::checkMasterLogin(textUser, textPass))
    {
        ui.loginMessage->setText("login successful");
        return;
    }

    ui.loginMessage->setText("Either username or password is incorrect");
}

void PWManager::on_signup_clicked()
{
    std::string textUser = ui.susername->text().toStdString();
    std::string textPass = ui.spassword->text().toStdString();

    if (passwordManager::createMasterLogin(textUser, textPass))
    {
        ui.loginMessage->setText("login successfully created");
        return;
    }
    ui.loginMessage->setText("login was not created");

}

void PWManager::on_switchs_clicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}

void PWManager::on_switchl_clicked()
{
    ui.stackedWidget->setCurrentIndex(1);
}

PWManager::~PWManager()
{}
