#include "PWManager.h"
#include "login.h"
#include "mainpasswordmenu.h"
#include "board.h"
#include "gamePassword.h"
#include "AuthManager.h"

#include <string>
#include <QGraphicsScene>

game::Board* game::Board::instancePtr = NULL;

PWManager::PWManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    setHash(game::generatePassword());

    //create qaction pointers for eye visibility toggle on password fields
    QAction* vaction = ui.password->addAction(QIcon("icons/eyeopen.png"), QLineEdit::TrailingPosition);
    QAction* vsaction = ui.spassword->addAction(QIcon("icons/eyeopen.png"), QLineEdit::TrailingPosition);

    //lambda function to connect eye action buttons to visible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this] { visible(ui.password); });
    QObject::connect(vsaction, &QAction::triggered, this, [vsaction, this] { visible(ui.spassword); });

    //scene for game
    QGraphicsScene* scene = new QGraphicsScene(this);
    game::Board* b = game::Board::getInstance();

    //connect chess buttons to clicked functions
    QObject::connect(ui.resetLogin, &QPushButton::clicked, this, [this] { on_reset_clicked(); });
    QObject::connect(ui.resetSignUp, &QPushButton::clicked, this, [this] { on_reset_clicked(); });

    QObject::connect(ui.chessLogin, &QPushButton::clicked, this, [this] { on_chess_clicked(); });
    QObject::connect(ui.chessSignUp, &QPushButton::clicked, this, [this] { on_chess_clicked(); });

    QObject::connect(ui.checkersLogin, &QPushButton::clicked, this, [this] { on_checkers_clicked(); });
    QObject::connect(ui.checkersSignUp, &QPushButton::clicked, this, [this] { on_checkers_clicked(); });

    scene->addItem(b);
    ui.view->setScene(scene);
    ui.view2->setScene(scene);

    //connect scene change signal to password linedit on corresponding screen
    QObject::connect(scene, &QGraphicsScene::changed, this, [scene, this, b] 
        { 
            ui.password->setText(QString::fromStdString(game::moveHashFuction(b->getPlayedMoves(), database::getGameHashFromDB(ui.username->text().toStdString())))); 
            ui.spassword->setText(QString::fromStdString(game::moveHashFuction(b->getPlayedMoves(), getHash())));
        });

    QObject::connect(ui.username, &QLineEdit::textChanged, this, [scene, this, b] 
        { 
            std::string h = database::getGameHashFromDB(ui.username->text().toStdString());
            QString newPass = QString::fromStdString(game::moveHashFuction(b->getPlayedMoves(), h));
            if (!newPass.isEmpty())
            {
               ui.password->setText(newPass);
            }
        });
}

//set passwordfield be visible and change icon. used for both sign up and login page
void PWManager::visible(QLineEdit* pwField)
{
    //use either sign up or login pw field to get corresponding action
    pwField->setEchoMode(QLineEdit::Normal);
    QAction* vaction = pwField->findChild<QAction*>();
    vaction->setIcon(QIcon("icons/eyeclose.png"));

    vaction->disconnect();
    //connect toggle back to invisible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this, pwField] { invisible(pwField); });

}

void PWManager::invisible(QLineEdit* pwField)
{
    //use either sign up or login pw field to get corresponding action
    pwField->setEchoMode(QLineEdit::Password);
    QAction* vaction = pwField->findChild<QAction*>();
    vaction->setIcon(QIcon("icons/eyeopen.png"));

    vaction->disconnect();
    //connect toggle back to visible function
    QObject::connect(vaction, &QAction::triggered, this, [vaction, this, pwField] { visible(pwField); });
}

//login page to log in to password manager
void PWManager::on_login_clicked()
{
    std::string textUser = ui.username->text().toStdString();
    std::string textPass = ui.password->text().toStdString();

    // The UI passes the raw text to the controller, and the controller handles the rest
    controllers::AuthResult result = controllers::AuthManager::attemptLogin(textUser, textPass);

    if (!result.success)
    {
        ui.loginMessage->setText(QString::fromStdString(result.message));
        return;
    }

    game::Board* b = game::Board::getInstance();
    b->resetBoard();

    this->close();

    // Create new window using the clean data returned from AuthManager
    window = new mainpasswordmenu();
    window->setID(result.userId);
    window->setGameHash(result.gameHash);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}

void PWManager::on_signup_clicked()
{
    std::string textUser = ui.susername->text().toStdString();
    std::string textPass = ui.spassword->text().toStdString();

    // Let AuthManager handle the regex rules and the registration pipeline
    controllers::AuthResult result = controllers::AuthManager::registerAccount(textUser, textPass, getHash());

    ui.loginMessage->setText(QString::fromStdString(result.message));
}


//toolbar action to switch to sign up page
void PWManager::on_actionSignUp_triggered()
{
    game::Board* b = game::Board::getInstance();
    b->resetBoard();

    ui.stackedWidget->setCurrentIndex(0);
    ui.loginMessage->setText("");
}

//toolbar action to switch to login page
void PWManager::on_actionLogIn_triggered()
{
    game::Board* b = game::Board::getInstance();
    b->resetBoard();

    ui.stackedWidget->setCurrentIndex(1);
    ui.loginMessage->setText("");
}

void PWManager::on_reset_clicked()
{
    game::Board* b = game::Board::getInstance();
    b->resetBoard();
}

void PWManager::on_chess_clicked()
{
    game::Board* b = game::Board::getInstance();

    if (b->getGame() != game::CHESS)
    {
        b->setGame(game::CHESS);
        b->resetBoard();
    }
}

void PWManager::on_checkers_clicked()
{
    game::Board* b = game::Board::getInstance();
   
    if (b->getGame() != game::CHECKERS)
    {
        b->setGame(game::CHECKERS);
        b->resetBoard();
    }
}

std::string PWManager::getHash()
{
    return gameHash;
}

void PWManager::setHash(std::string hash)
{
    gameHash = hash;
}

PWManager::~PWManager()
{}
