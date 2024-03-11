#include "accounts.h"
#include <fstream>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

namespace passwordManager
{
	bool createAccount(int userID, std::string email, std::string username, std::string password, std::string url, std::string app)
	{
        std::string server;
        std::string susername;
        std::string spassword;

        // Read from the text file
        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, susername);
        std::getline(rfile, spassword);

        // Close the file
        rfile.close();

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(susername));
        db.setPassword(QString::fromStdString(spassword));
        db.setDatabaseName("passwordmanager");

        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        QSqlQuery qry;
        qry.prepare("INSERT INTO accounts(email, username, password, url, application, userID) VALUES(?,?,?,?,?,?)");
        qry.addBindValue(QString::fromStdString(email));
        qry.addBindValue(QString::fromStdString(username));
        qry.addBindValue(QString::fromStdString(password));
        qry.addBindValue(QString::fromStdString(url));
        qry.addBindValue(QString::fromStdString(app));
        qry.addBindValue(userID);

        if (qry.exec())
        {
            db.close();
            return true;
        }

        db.close();
        return false;
	}

    bool deleteAccount(int id)
    {
        std::string server;
        std::string susername;
        std::string spassword;

        // Read from the text file
        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, susername);
        std::getline(rfile, spassword);

        // Close the file
        rfile.close();



        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(susername));
        db.setPassword(QString::fromStdString(spassword));
        db.setDatabaseName("passwordmanager");

        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        QSqlQuery qry;
        qry.prepare("DELETE FROM accounts WHERE id = ?");
        qry.addBindValue(id);

        if (qry.exec())
        {
            db.close();
            return true;
        }

        db.close();
        return false;
    }
}