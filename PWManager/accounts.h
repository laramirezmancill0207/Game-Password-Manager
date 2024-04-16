#pragma once
#include <string>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

namespace database
{
	/*
	* create account using supplied parameters
	* 
	*/
	bool createAccount(int userID, std::string email, std::string username, std::string password, std::string url, std::string app);

	//delete account from mysql database based on supplied id
	bool deleteAccount(int id);

	/*
	* get all the accounts for a given user from mysql db based on id
	* returned in qt QSqlQueryModel to populate a tableview
	*/
	QSqlQueryModel* getAccounts(int userID);
}
