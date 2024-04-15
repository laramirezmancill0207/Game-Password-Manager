#include "PWManager.h"
#include "login.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString val;
    QFile file;
    file.setFileName("database.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject data = doc.object();
    QJsonValue value = data.value(QString("database"));

    QJsonValue driver = value["driver"];
    QJsonValue host = value["host"];
    QJsonValue schema = value["database"];
    QJsonValue user = value["user"];
    QJsonValue password = value["password"];

    //create qdatabase to access mysql passwordmanager database
    QSqlDatabase db = QSqlDatabase::addDatabase(driver.toString());
    db.setHostName(host.toString());
    db.setUserName(user.toString());
    db.setPassword(password.toString());
    db.setDatabaseName(schema.toString());

    PWManager w;
    w.show();
    return a.exec();
}
