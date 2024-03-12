#pragma once
#include <string>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

namespace passwordManager
{
	bool createAccount(int userID, std::string email, std::string username, std::string password, std::string url, std::string app);
	bool deleteAccount(int id);
	QSqlQueryModel* getAccounts(int userID);
}
