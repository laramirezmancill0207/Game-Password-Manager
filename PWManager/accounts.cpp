#include "accounts.h"
#include <fstream>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

namespace passwordManager
{
    //create ne account in accounts table
	bool createAccount(int userID, std::string email, std::string username, std::string password, std::string url, std::string app)
	{
        //set up server variables from txt file
        std::string server;
        std::string susername;
        std::string spassword;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, susername);
        std::getline(rfile, spassword);
        rfile.close();

        //create qdatabase to access mysql passwordmanager database
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(susername));
        db.setPassword(QString::fromStdString(spassword));
        db.setDatabaseName("passwordmanager");

        //if db does not open show error and return false
        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        //create insertion query for account into accounts table
        QSqlQuery qry;
        qry.prepare("INSERT INTO accounts(email, username, password, url, application, userID) VALUES(?,?,?,?,?,?)");
        qry.addBindValue(QString::fromStdString(email));
        qry.addBindValue(QString::fromStdString(username));
        qry.addBindValue(QString::fromStdString(password));
        qry.addBindValue(QString::fromStdString(url));
        qry.addBindValue(QString::fromStdString(app));
        qry.addBindValue(userID);

        //if qry not able to execute return last error
        if (!qry.exec())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        db.close();
        return true;
	}

    //delete one account from accounts table
    bool deleteAccount(int id)
    {
        //set up server variables from txt file
        std::string server;
        std::string susername;
        std::string spassword;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, susername);
        std::getline(rfile, spassword);
        rfile.close();


        //create qdatabase to access mysql passwordmanager database
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

        //qry to delete an account with specified id
        QSqlQuery qry;
        qry.prepare("DELETE FROM accounts WHERE id = ?");
        qry.addBindValue(id);

        if (!qry.exec())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        db.close();
        return true;
    }

    //get user accounts model for table from mysql accounts db
    QSqlQueryModel* getAccounts(int userID) 
    {
        QSqlQueryModel* model = new QSqlQueryModel();

        //set up server variables from txt file
        std::string server;
        std::string susername;
        std::string spassword;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, susername);
        std::getline(rfile, spassword);
        rfile.close();


        //connect to mysql db
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(susername));
        db.setPassword(QString::fromStdString(spassword));
        db.setDatabaseName("passwordmanager");

        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return NULL;
        }

        //qry to select all accounts from a user
        QSqlQuery qry;
        qry.prepare("SELECT * FROM accounts WHERE userID = ?");
        qry.addBindValue(userID);

        //if qry executes set model based on qry selection
        if (qry.exec())
        {
            model->setQuery(qry);
            db.close();
            return model;
        }

        qDebug() << db.lastError();
        db.close();
        return NULL;
    }
}