#include "mainpasswordmenu.h"
#include "accounts.h"
#include "aboutPage.h"
#include <iostream>
#include <fstream>

#include <QMessageBox>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFontDatabase>
#include <QGraphicsScene>
#include <QClipboard>

#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>

#include "board.h"
#include "gamePassword.h"
#include "bcrypt/BCrypt.hpp"

mainpasswordmenu::mainpasswordmenu(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	//setup menu icons
	this->homeMenu->setIcon(QIcon("icons/home.png"));
	this->gameMenu->setIcon(QIcon("icons/game.png"));
	this->settingsMenu->setIcon(QIcon("icons/.png"));
	this->profile->setIcon(QIcon("icons/profile.png"));

	//setup search bar
	this->searchBar->addAction(QIcon("icons/search.png"), QLineEdit::LeadingPosition);
	QObject::connect(this->searchBar, &QLineEdit::textChanged, this, [this] { refreshTable(); });

	this->homeMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	
	//setup tableview formatting
	this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->tableView->verticalHeader()->hide();
	this->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

	//connect all menubar actions to appropriate function
	QObject::connect(this->actionGithub, &QAction::triggered, this, [this] { ShellExecute(NULL, L"open", L"https://github.com/laramirezmancill0207/Game-Password-Manager", nullptr, nullptr, SW_SHOWNORMAL); });
	QObject::connect(this->actionAbout, &QAction::triggered, this, [this] { aboutMenu(); });

	//handle showing and hiding add widget on main menu
	this->actionAdd_Menu->setChecked(true);
	QObject::connect(this->actionAdd_Menu, &QAction::triggered, this, [this] { if (this->actionAdd_Menu->isChecked()) { this->addFrame->show(); } else { this->addFrame->hide(); }; });
	
	//handle showing and hiding delete widget on main menu
	this->actionDelete_Menu->setChecked(true);
	QObject::connect(this->actionDelete_Menu, &QAction::triggered, this, [this] { if (this->actionDelete_Menu->isChecked()) { this->deleteWidget->show(); } else { this->deleteWidget->hide(); }; });

	//setup game scene
	QGraphicsScene* scene = new QGraphicsScene(this);
	game::Board* b = game::Board::getInstance();
	scene->addItem(b);
	QPixmap pim("images/background.png");
	scene->setBackgroundBrush(pim.scaled(scene->width(), scene->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	this->graphicsView->setScene(scene);

	//connect chess buttons to clicked functions
	QObject::connect(this->resetButton, &QPushButton::clicked, this, [this] { on_reset_clicked(); });
	QObject::connect(this->chessButton, &QPushButton::clicked, this, [this] { on_chess_clicked(); });
	QObject::connect(this->checkersButton, &QPushButton::clicked, this, [this] { on_checkers_clicked(); });

	/*
	* connect scene change to password linedit
	* 
	*/
	QObject::connect(scene, &QGraphicsScene::changed, this, [scene, this, b] { this->generatedPass->setText(QString::fromStdString(game::moveHashFuction(b->getPlayedMoves(), getGameHash()))); });

}

/// <summary>
/// home menu functions
/// </summary>

void mainpasswordmenu::aboutMenu()
{
	//create window for about page
	aboutPage* about = new aboutPage();

	about->setModal(true);
	about->setFixedSize(600, 400);

	about->exec();
}

void mainpasswordmenu::refreshTable()
{
	//use id to get user accounts and set up table model
	int userID = getID();
	QSqlQueryModel* model = database::getAccounts(userID);
	QSortFilterProxyModel* m = new QSortFilterProxyModel();

	//use string "test" to filter table based on 4th column (application)
	QString test = this->searchBar->text();
	m->setSourceModel(model);
	m->setFilterKeyColumn(4);
	m->setFilterFixedString(test);

	this->tableView->setModel(m);
	this->tableView->setColumnHidden(0, true);
}


void mainpasswordmenu::on_addAccount_clicked()
{
	std::string accemail = this->accemail->text().toStdString();
	std::string accusername = this->accusername->text().toStdString();
	std::string accpassword = this->accpassword->text().toStdString();
	std::string accurl = this->accurl->text().toStdString();
	std::string accapp = this->accapp->text().toStdString();

	int userID = getID();

	//check if all fields entered
	if (accemail.empty() || accusername.empty() || accpassword.empty() || accurl.empty() || accapp.empty())
	{
		QMessageBox::about(NULL, "Warning", "Please fill all fields");

		return;
	}

	//try to create account
	bool created = database::createAccount(userID, accemail, accusername, accpassword, accurl, accapp);

	if (!created)
	{
		QMessageBox::about(NULL, "Warning", "Account not able to be added");
		return;
	}

	//refresh table after account added
	mainpasswordmenu::refreshTable();
	
}

void mainpasswordmenu::on_deleteAccount_clicked()
{
	QModelIndexList selection = tableView->selectionModel()->selectedRows();

	//if no rows selected
	if (selection.isEmpty())
	{
		QMessageBox::about(NULL, "Account Deletion", "No Account Selected");
		return;
	}

	//message box to ask user if they are sure they want to delete account
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(NULL, "Account Deletion", "Delete Account?",
		QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::No) {
		return;
	}

	this->tableView->setColumnHidden(0, false);

	//iterate through selected rows
	for (int i = 0; i < selection.count(); i++)
	{
		QModelIndex index = selection.at(i);

		int id = -1;

		try
		{
			//get row id from hidden column
			id = stoi(index.data().toString().toStdString());
		}

		catch (std::exception& err)
		{
			//this->warning->setText("error please log out and log back in");
			QMessageBox::about(NULL, "Error", "Please log out and log back in");

			return;
		}

		if (!database::deleteAccount(id))
		{
			QMessageBox::about(NULL, "Error", "Account does not exist");

			return;
		}
	}

	//if account deleted refresh table
	mainpasswordmenu::refreshTable();
}

void mainpasswordmenu::on_resetButton_clicked()
{
	game::Board* b = game::Board::getInstance();
	b->resetBoard();
}

void mainpasswordmenu::on_copyPassButton_clicked()
{
	if (!generatedPass->text().isEmpty())
	{
		QClipboard* clipboard = QGuiApplication::clipboard();
		clipboard->setText(QString::fromStdString(generatedPass->text().toStdString()));
	}
}

void mainpasswordmenu::on_homeMenu_clicked()
{
	//switch stackedwidget index and highlight selected button
	this->stackedWidget->setCurrentIndex(0);
	this->homeMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->gameMenu->setStyleSheet("");
	this->settingsMenu->setStyleSheet("");

	this->menuWindow->menuAction()->setVisible(true);
	//this->menuWindow->setEnabled(true);
}

void mainpasswordmenu::on_gameMenu_clicked()
{
	//switch stackedwidget index and highlight selected button
	this->stackedWidget->setCurrentIndex(1);
	this->gameMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->homeMenu->setStyleSheet("");
	this->settingsMenu->setStyleSheet("");

	this->menuWindow->menuAction()->setVisible(false);
	//this->menuWindow->setEnabled(false);
}

void mainpasswordmenu::on_settingsMenu_clicked()
{
	//switch stackedwidget index and highlight selected button
	this->stackedWidget->setCurrentIndex(2);
	this->settingsMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->gameMenu->setStyleSheet("");
	this->homeMenu->setStyleSheet("");

	this->menuWindow->menuAction()->setVisible(false);
	//this->menuWindow->setEnabled(false);
}

void mainpasswordmenu::on_reset_clicked()
{
	game::Board* b = game::Board::getInstance();
	b->resetBoard();
}

void mainpasswordmenu::on_chess_clicked()
{
	game::Board* b = game::Board::getInstance();

	if (b->getGame() != game::CHESS)
	{
		b->setGame(game::CHESS);
		b->resetBoard();
	}
}

void mainpasswordmenu::on_checkers_clicked()
{
	game::Board* b = game::Board::getInstance();

	if (b->getGame() != game::CHECKERS)
	{
		b->setGame(game::CHECKERS);
		b->resetBoard();
	}
}

void mainpasswordmenu::showEvent(QShowEvent* event)
{
	QWidget::showEvent(event);

	refreshTable();
}

void mainpasswordmenu::closeEvent(QCloseEvent* event)
{
	QApplication::quit();
}

int mainpasswordmenu::getID()
{
	return id;
}

void mainpasswordmenu::setID(int userID)
{
	this->id = userID;
}

std::string mainpasswordmenu::getGameHash()
{
	return gameHash;
}
void mainpasswordmenu::setGameHash(std::string gameH)
{
	gameHash = gameH;
}

/// <summary>
/// game menu functions
/// </summary>



mainpasswordmenu::~mainpasswordmenu()
{}
