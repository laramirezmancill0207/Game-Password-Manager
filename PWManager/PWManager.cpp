#include "PWManager.h"
#include "login.h"
#include <string>
#include "mainpasswordmenu.h"



PWManager::PWManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //create qaction pointers for eye visibility toggle on password fields
    QAction* vaction = ui.password->addAction(QIcon("eyeopen.png"), QLineEdit::TrailingPosition);
    QAction* vsaction = ui.spassword->addAction(QIcon("eyeopen.png"), QLineEdit::TrailingPosition);

    //lambda function to connect eye action buttons to visible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this] { visible(ui.password); });
    QObject::connect(vsaction, &QAction::triggered, this, [vsaction, this] { visible(ui.spassword); });
}

//set passwordfield be visible and change icon. used for both sign up and login page
void PWManager::visible(QLineEdit* pwField)
{
    //use either sign up or login pw field to get corresponding action
    pwField->setEchoMode(QLineEdit::Normal);
    QAction* vaction = pwField->findChild<QAction*>();
    vaction->setIcon(QIcon("eyeclose.png"));

    vaction->disconnect();
    //connect toggle back to invisible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this, pwField] { invisible(pwField); });

}

void PWManager::invisible(QLineEdit* pwField)
{
    //use either sign up or login pw field to get corresponding action
    pwField->setEchoMode(QLineEdit::Password);
    QAction* vaction = pwField->findChild<QAction*>();
    vaction->setIcon(QIcon("eyeopen.png"));

    vaction->disconnect();
    //connect toggle back to visible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this, pwField] { visible(pwField); });
}

//login page to log in to password manager
void PWManager::on_login_clicked()
{
    std::string textUser = ui.username->text().toStdString();
    std::string textPass = ui.password->text().toStdString();

    if (textUser.empty() || textPass.empty())
    {
        ui.loginMessage->setText("Please enter both a username and password");
        return;
    }

    //get user object from mysql database using entered username and passowrd
    passwordManager::User masteruser = passwordManager::checkMasterLogin(textUser, textPass);

    //if either is empty username or password was incorrect
    if (masteruser.getUsername().empty() || masteruser.getUserID() == -1)
    {
        ui.loginMessage->setText("Either username or password is incorrect");
        return;
    }

    //create new window for main password manager if login successful
    window = new mainpasswordmenu();

    //set hidden label to userID for later use
    window->label_6->setText(QString::number(masteruser.getUserID()));
    window->label_6->setHidden(true);

    window->actionUsername->setText(QString::fromStdString(textUser));

    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();

    this->close();
}

//sign up page when sign up button clicked
void PWManager::on_signup_clicked()
{
    std::string textUser = ui.susername->text().toStdString();
    std::string textPass = ui.spassword->text().toStdString();

    //check if password meets requirements
    std::string check = passwordManager::checkPassword(textPass);

    //if check is not good set warning label to return message
    if (check != "good") {

        ui.loginMessage->setText(QString::fromStdString(check));
        return;
    }

    //use createmasterlogin function to put new user into db
    if (passwordManager::createMasterLogin(textUser, textPass))
    {
        ui.loginMessage->setText("login successfully created");
        return;
    }

    ui.loginMessage->setText("login was not able to be created");

}

//toolbar action to switch to sign up page
void PWManager::on_actionSignUp_triggered()
{
    ui.stackedWidget->setCurrentIndex(0);
    ui.loginMessage->setText("");
}

//toolbar action to switch to login page
void PWManager::on_actionLogIn_triggered()
{
    ui.stackedWidget->setCurrentIndex(1);
    ui.loginMessage->setText("");
}

PWManager::~PWManager()
{}
