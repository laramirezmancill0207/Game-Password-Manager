#include "PWManager.h"
#include "login.h"
#include <string>
#include "mainpasswordmenu.h"
#include <QSignalMapper>


PWManager::PWManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QAction* vaction = ui.password->addAction(QIcon("eyeopen.png"), QLineEdit::TrailingPosition);
    QAction* vsaction = ui.spassword->addAction(QIcon("eyeopen.png"), QLineEdit::TrailingPosition);

    QObject::connect(vaction, SIGNAL(triggered()), this, SLOT(visible()));
    QObject::connect(vsaction, SIGNAL(triggered()), this, SLOT(visible()));

    //QSignalMapper* signalMapper = new QSignalMapper(this);

    
    //QObject::connect(vaction, SIGNAL(triggered()), signalMapper, SLOT(map()));
    //QObject::connect(vsaction, SIGNAL(triggered()), signalMapper, SLOT(map()));

    /*
    signalMapper->setMapping(vaction, ui.password);
    signalMapper->setMapping(vsaction, ui.spassword);
    
    QObject::connect(signalMapper, SIGNAL(mapped(QLineEdit*)), this, SLOT(visible(QLineEdit*)));
    */

}

void PWManager::visible()
{
    if (ui.stackedWidget->currentIndex() == 1)
    {
        ui.password->setEchoMode(QLineEdit::Normal);

        QAction* vaction = ui.password->findChild<QAction*>();
        vaction->setIcon(QIcon("eyeclose.png"));

        QObject::connect(vaction, SIGNAL(triggered()), this, SLOT(invisible()));
    }
    else if (ui.stackedWidget->currentIndex() == 0)
    {
        ui.spassword->setEchoMode(QLineEdit::Normal);

        QAction* vsaction = ui.spassword->findChild<QAction*>();
        vsaction->setIcon(QIcon("eyeclose.png"));

        QObject::connect(vsaction, SIGNAL(triggered()), this, SLOT(invisible()));
    }
    
}

void PWManager::invisible()
{
    if (ui.stackedWidget->currentIndex() == 1)
    {
        ui.password->setEchoMode(QLineEdit::Password);

        QAction* vaction = ui.password->findChild<QAction*>();
        vaction->setIcon(QIcon("eyeopen.png"));

        QObject::connect(vaction, SIGNAL(triggered()), this, SLOT(visible()));
    }
    else if (ui.stackedWidget->currentIndex() == 0)
    {
        ui.spassword->setEchoMode(QLineEdit::Password);

        QAction* vsaction = ui.spassword->findChild<QAction*>();
        vsaction->setIcon(QIcon("eyeopen.png"));

        QObject::connect(vsaction, SIGNAL(triggered()), this, SLOT(visible()));
    }
}

void PWManager::on_login_clicked()
{
    
    std::string textUser = ui.username->text().toStdString();
    std::string textPass = ui.password->text().toStdString();

    //exit function if username or password is empty
    if (textUser.empty() || textPass.empty())
    {
        ui.loginMessage->setText("Please enter both a username and password");
        return;
    }

    passwordManager::User masteruser = passwordManager::checkMasterLogin(textUser, textPass);

    if (masteruser.getUsername().empty() || masteruser.getUserID() == -1)
    {
        ui.loginMessage->setText("Either username or password is incorrect");
        return;
    }

    window = new mainpasswordmenu();

    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
    window->actionUsername->setText(QString::fromStdString(textUser));

    window->label_6->setText(QString::number(masteruser.getUserID()));
    window->label_6->setHidden(true);

    this->close();
}

void PWManager::on_signup_clicked()
{
    std::string textUser = ui.susername->text().toStdString();
    std::string textPass = ui.spassword->text().toStdString();

    std::string check = passwordManager::checkPassword(textPass);

    if (check != "good") {

        ui.loginMessage->setText(QString::fromStdString(check));
        return;
    }

    if (passwordManager::createMasterLogin(textUser, textPass))
    {
        ui.loginMessage->setText("login successfully created");
        return;
    }
    ui.loginMessage->setText("login was not created");

}

void PWManager::on_actionSignUp_triggered()
{
    ui.stackedWidget->setCurrentIndex(0);
    ui.loginMessage->setText("");
}

void PWManager::on_actionLogIn_triggered()
{
    ui.stackedWidget->setCurrentIndex(1);
    ui.loginMessage->setText("");
}

PWManager::~PWManager()
{}
