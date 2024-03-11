#include "login.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace passwordManager
{
    User checkMasterLogin(std::string inputU, std::string inputP)
    {
        std::string server;
        std::string username;
        std::string password;

        // Read from the text file
        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, username);
        std::getline(rfile, password);

        // Close the file
        rfile.close();



        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(username));
        db.setPassword(QString::fromStdString(password));
        db.setDatabaseName("passwordmanager");

        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return User("", "", -1);
        }

        QSqlQuery qry;
        qry.prepare("SELECT * FROM masteruser WHERE username = ? AND password = ?");
        qry.addBindValue(QString::fromStdString(inputU));
        qry.addBindValue(QString::fromStdString(inputP));

        if (qry.exec())
        {
            if (qry.next())
            {
                db.close();
                return User(qry.value("username").toString().toStdString(), qry.value("password").toString().toStdString(), qry.value("id").toInt());
            }
        }
        db.close();
        return User("", "", -1);

    }
    

    bool createMasterLogin(std::string inputU, std::string inputP)
    {

        std::string server;
        std::string username;
        std::string password;

        // Read from the text file
        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, username);
        std::getline(rfile, password);

        // Close the file
        rfile.close();

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(username));
        db.setPassword(QString::fromStdString(password));
        db.setDatabaseName("passwordmanager");

        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        QSqlQuery qry;
        qry.prepare("INSERT INTO masteruser(username, password) VALUES(?,?)");
        qry.addBindValue(QString::fromStdString(inputU));
        qry.addBindValue(QString::fromStdString(inputP));

        if (qry.exec())
        {
            db.close();
            return true;
        }

        db.close();
        return false;

    }
    

    std::string checkPassword(std::string password)
    {

        std::regex rules("(?=.*\d)(?=.*[a-z])(?=.*[A-Z])((?=.*\W)|(?=.*_))^[^ ]+$");

        if (!std::regex_match(password, rules))
        {
            return "Password rules: at least one lower case, upper case, digit, special character\nAlso no underscore, or spaces";
        }

        if (password.length() < 8)
        {
            return "Password must be 8 characters or more";
        }

        



        return "good";
    }
}