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


namespace database
{
    User getUserByUsername(std::string inputU)
    {
        QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection);

        //if db not able to open show error and return empty user
        if (!db.open()) {
            qDebug() << db.lastError();
            return User("", "", "", -1);
        }

        //query to select the user with entered username and password
        QSqlQuery qry;
        qry.prepare("SELECT * FROM masteruser WHERE username = ?");
        qry.addBindValue(QString::fromStdString(inputU));

        //run if query can not be executed
        if (!qry.exec()) {
            qDebug() << db.lastError();
            db.close();
            return User("", "", "", -1);
        }

        // If the user exists, return the database row as a User object
        if (qry.next()) {
            User foundUser(
                qry.value("username").toString().toStdString(),
                qry.value("password").toString().toStdString(),
                qry.value("gameHash").toString().toStdString(),
                qry.value("id").toInt()
            );
            db.close();
            return foundUser;
        }

        db.close();
        return User("", "", "", -1);
    }

    bool createMasterLogin(std::string inputU, std::string hashedPassword, std::string generatedPass)
    {
        QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection);

        if (!db.open()) {
            qDebug() << db.lastError();
            return false;
        }

        QSqlQuery qry;
        qry.prepare("INSERT INTO masteruser (username, password, gameHash) VALUES(?,?,?)");
        qry.addBindValue(QString::fromStdString(inputU));
        // The password is now hashed before it reaches this function
        qry.addBindValue(QString::fromStdString(hashedPassword));
        qry.addBindValue(QString::fromStdString(generatedPass));

        if (!qry.exec()) {
            qDebug() << db.lastError();
            db.close();
            return false;
        }

        db.close();
        return true;
    }
    
    std::string getGameHashFromDB(std::string inputU)
    {
        QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection);

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