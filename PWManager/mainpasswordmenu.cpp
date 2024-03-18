#include "mainpasswordmenu.h"
#include "accounts.h"
#include <iostream>
#include <fstream>

#include <QMessageBox>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFontDatabase>

#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>

mainpasswordmenu::mainpasswordmenu(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	this->homeMenu->setIcon(QIcon("home.png"));
	this->gameMenu->setIcon(QIcon("game.png"));
	this->settingsMenu->setIcon(QIcon("settings.png"));

	this->searchBar->addAction(QIcon("search.png"), QLineEdit::LeadingPosition);

	this->homeMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
		
	this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	this->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->tableView->verticalHeader()->hide();

	this->tableView->horizontalHeader()->setFont(QFont("Dubai", 12, QFont::Bold));
	//this->tableView->verticalHeader()->setFont(QFont("Dubai"));

	QObject::connect(this->searchBar, &QLineEdit::textChanged, this, [this] { refreshTable(); });

	//connect all menubar actions to appropriate function
	QObject::connect(this->actionGithub, &QAction::triggered, this, [this] { ShellExecute(NULL, L"open", L"https://github.com/laramirezmancill0207/Game-Password-Manager", nullptr, nullptr, SW_SHOWNORMAL); });
	QObject::connect(this->actionAbout, &QAction::triggered, this, [this] { aboutMenu(); });


}

void mainpasswordmenu::aboutMenu()
{

}

void mainpasswordmenu::refreshTable()
{
	int userID = -1;

	try
	{
		userID = stoi(this->label_6->text().toStdString());
	}

	catch (std::exception& err)
	{
		//this->warning->setText("error please log out and log back in");
		QMessageBox::about(NULL, "Error", "Please log out and log back in");

		return;
	}

	QSqlQueryModel* model = passwordManager::getAccounts(userID);

	QSortFilterProxyModel* m = new QSortFilterProxyModel();

	QString test = this->searchBar->text();

	m->setSourceModel(model);
	m->setFilterKeyColumn(4);
	m->setFilterFixedString(test);

	

	this->tableView->setModel(m);
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

void mainpasswordmenu::on_addAccount_clicked()
{
	std::string accemail = this->accemail->text().toStdString();
	std::string accusername = this->accusername->text().toStdString();
	std::string accpassword = this->accpassword->text().toStdString();
	std::string accurl = this->accurl->text().toStdString();
	std::string accapp = this->accapp->text().toStdString();

	int userID;

	try
	{
		userID = stoi(this->label_6->text().toStdString());
	}

	catch (std::exception &err)
	{
		//this->warning->setText("error please log out and log back in");
		QMessageBox::about(NULL, "Error", "Please log out and log back in");

		return;
	}

	//check if all fields entered
	if (accemail.empty() || accusername.empty() || accpassword.empty() || accurl.empty() || accapp.empty())
	{
		//this->warning->setText("Please fill all fields");
		QMessageBox::about(NULL, "Warning", "Please fill all fields");

		return;
	}

	bool created = passwordManager::createAccount(userID, accemail, accusername, accpassword, accurl, accapp);

	if (!created)
	{
		//this->warning->setText("account not able to be added");
		QMessageBox::about(NULL, "Warning", "Account not able to be added");
		return;
	}

	mainpasswordmenu::refreshTable();
	
}

void mainpasswordmenu::on_deleteAccount_clicked()
{
	QModelIndexList selection = tableView->selectionModel()->selectedRows();

	if (selection.isEmpty())
	{
		QMessageBox::about(NULL, "Account Deletion", "No Account Selected");
		return;
	}

	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(NULL, "Account Deletion", "Delete Account?",
		QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::No) {
		return;
	}

	// Multiple rows can be selected
	for (int i = 0; i < selection.count(); i++)
	{
		QModelIndex index = selection.at(i);
		//qDebug() << index.data().toString();

		int id = -1;

		try
		{
			id = stoi(index.data().toString().toStdString());
		}

		catch (std::exception& err)
		{
			//this->warning->setText("error please log out and log back in");
			QMessageBox::about(NULL, "Error", "Please log out and log back in");

			return;
		}

		if (passwordManager::deleteAccount(id))
		{
			QMessageBox::about(NULL, "Error", "Account does not exist");

			return;
		}
	}

	mainpasswordmenu::refreshTable();
}

void mainpasswordmenu::on_homeMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(0);
	this->homeMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->gameMenu->setStyleSheet("");
	this->settingsMenu->setStyleSheet("");
}

void mainpasswordmenu::on_gameMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(1);
	this->gameMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->homeMenu->setStyleSheet("");
	this->settingsMenu->setStyleSheet("");
}

void mainpasswordmenu::on_settingsMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(2);
	this->settingsMenu->setStyleSheet("background-color: rgb(255, 255, 255);");
	this->gameMenu->setStyleSheet("");
	this->homeMenu->setStyleSheet("");
}

mainpasswordmenu::~mainpasswordmenu()
{}
