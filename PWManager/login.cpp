#include "login.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

//Qt SQL includes
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include "bcrypt/BCrypt.hpp"


namespace passwordManager
{
    User checkMasterLogin(std::string inputU, std::string inputP)
    {
        //set up server variables from txt file
        std::string server;
        std::string username;
        std::string password;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, username);
        std::getline(rfile, password);

        // Close the file
        rfile.close();


        //create qdatabase to access mysql passwordmanager database
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(username));
        db.setPassword(QString::fromStdString(password));
        db.setDatabaseName("passwordmanager");

        //if db not able to open show error and return empty user
        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return User("", "", "", - 1);
        }

        //query to select the user with entered username and password
        QSqlQuery qry;
        qry.prepare("SELECT * FROM masteruser WHERE username = ?");
        qry.addBindValue(QString::fromStdString(inputU));

        //run if query can not be executed
        if (!qry.exec())
        {
            qDebug() << db.lastError();
            db.close();
            return User("", "", "", - 1);
        }

        //if selection exists, (only one can exist based on db requirements) return the user with db values
        if (qry.next())
        {

            std::string pw = qry.value("password").toString().toStdString();

            if (BCrypt::validatePassword(inputP, pw))
            {
                db.close();
                return User(qry.value("username").toString().toStdString(), qry.value("password").toString().toStdString(), qry.value("gameHash").toString().toStdString(), qry.value("id").toInt());
            }

        }

        db.close();
        return User("", "", "", - 1);
    }
    

    bool createMasterLogin(std::string inputU, std::string inputP, std::string generatedPass)
    {
        //set up server variables from txt file
        std::string server;
        std::string username;
        std::string password;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, username);
        std::getline(rfile, password);

        // Close the file
        rfile.close();

        //create qdatabase to access mysql passwordmanager database
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

        //hash using bcrypt
        QString hashed = QString::fromStdString(BCrypt::generateHash(inputP));


        //query to insert a new user into masteruser table with entered values
        QSqlQuery qry;
        qry.prepare("INSERT INTO masteruser (username, password, gameHash) VALUES(?,?,?)");
        qry.addBindValue(QString::fromStdString(inputU));
        qry.addBindValue(hashed);
        qry.addBindValue(QString::fromStdString(generatedPass));

        //if query cant execute return false
        if (!qry.exec())
        {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        db.close();
        return true;

    }
    
    std::string getGameHashFromDB(std::string inputU)
    {
        //set up server variables from txt file
        std::string server;
        std::string username;
        std::string password;

        std::ifstream rfile("pw.txt");

        std::getline(rfile, server);
        std::getline(rfile, username);
        std::getline(rfile, password);

        // Close the file
        rfile.close();

        //create qdatabase to access mysql passwordmanager database
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(server));
        db.setUserName(QString::fromStdString(username));
        db.setPassword(QString::fromStdString(password));
        db.setDatabaseName("passwordmanager");



        if (!db.open())
        {
            qDebug() << db.lastError();
            db.close();
            return "";
        }

        //query to insert a new user into masteruser table with entered values
        QSqlQuery qry;
        qry.prepare("SELECT gameHash FROM masteruser WHERE username = ?");
        qry.addBindValue(QString::fromStdString(inputU));

        //if query cant execute return false
        if (!qry.exec())
        {
            qDebug() << db.lastError();
            db.close();
            return "";
        }

        if (qry.next())
        {
            db.close();

            return qry.value("gameHash").toString().toStdString();
        }

        db.close();
        return "";

    }

    std::string checkPassword(std::string password)
    {

        //if password is less than 8 characters
        if (password.length() < 8)
        {
            return "Password must be 8 characters or more";
        }

        //regex to check password for at least one lower case, upper case, digit, special character\nAlso no underscore, or spaces

        std::string reg = "^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?!.* ).{8,}$";

        std::regex rules(reg);

        //if password does not match regex rules
        if (!std::regex_match(password, rules))
        {
            return "Password rules: at least one lower case, upper case, digit\nAlso no spaces";
        }



        //if password meets all requirements return "good"
        return "good";
    }
}