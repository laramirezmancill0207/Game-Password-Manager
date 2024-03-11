#include "mainpasswordmenu.h"
#include "accounts.h"
#include <iostream>;
#include <fstream>

#include <QMessageBox>

mainpasswordmenu::mainpasswordmenu(QWidget *parent)
	: QMainWindow(parent)
{
	setupUi(this);

	
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
		this->warning->setText("error please log out and log back in");
		return;
	}

	//check if all fields entered
	if (accemail.empty() || accusername.empty() || accpassword.empty() || accurl.empty() || accapp.empty())
	{
		this->warning->setText("Please fill all fields");
		QMessageBox::about(this, "Warning", "Please fill all fields");

		return;
	}

	bool created = passwordManager::createAccount(userID, accemail, accusername, accpassword, accurl, accapp);

	if (!created)
	{
		this->warning->setText("account not able to be added");
		QMessageBox::about(this, "Warning", "Account not able to be added");
	}

	
}


mainpasswordmenu::~mainpasswordmenu()
{}
