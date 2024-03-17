#include "mainpasswordmenu.h"
#include "accounts.h"
#include <iostream>
#include <fstream>

#include <QMessageBox>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>

mainpasswordmenu::mainpasswordmenu(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

		
	this->tableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->tableView_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->tableView_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	QObject::connect(this->searchBar, &QLineEdit::textChanged, this, [this] { refreshTable(); });

	//connect all menubar actions to appropriate function
	QObject::connect(this->actionGithub, &QAction::triggered, this, [this] { ShellExecute(NULL, L"open", L"https://github.com/laramirezmancill0207/Game-Password-Manager", nullptr, nullptr, SW_SHOWNORMAL); });
	QObject::connect(this->actionAbout, &QAction::triggered, this, [this] { aboutMenu(); });
}

void aboutMenu()
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
		QMessageBox::about(this, "Error", "Please log out and log back in");

		return;
	}

	QSqlQueryModel* model = passwordManager::getAccounts(userID);

	QSortFilterProxyModel* m = new QSortFilterProxyModel();

	QString test = this->searchBar->text();

	m->setSourceModel(model);
	m->setFilterKeyColumn(5);
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
		QMessageBox::about(this, "Error", "Please log out and log back in");

		return;
	}

	//check if all fields entered
	if (accemail.empty() || accusername.empty() || accpassword.empty() || accurl.empty() || accapp.empty())
	{
		//this->warning->setText("Please fill all fields");
		QMessageBox::about(this, "Warning", "Please fill all fields");

		return;
	}

	bool created = passwordManager::createAccount(userID, accemail, accusername, accpassword, accurl, accapp);

	if (!created)
	{
		//this->warning->setText("account not able to be added");
		QMessageBox::about(this, "Warning", "Account not able to be added");
	}

	mainpasswordmenu::refreshTable();
	
}

void mainpasswordmenu::on_addMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(0);
}

void mainpasswordmenu::on_deleteMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(1);
}

void mainpasswordmenu::on_chessMenu_clicked()
{
	this->stackedWidget->setCurrentIndex(2);
}

mainpasswordmenu::~mainpasswordmenu()
{}
