#include "accounts.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

namespace passwordManager
{
	bool createAccount(int userID, std::string email, std::string username, std::string url, std::string app)
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



        //sql variables
        sql::Driver* driver;
        sql::Connection* con;
        sql::PreparedStatement* pstmt;

        //storage variables
        int userID;

        //try to get connection to sql server
        try
        {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
        }

        catch (sql::SQLException e)
        {
            std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
            system("pause");
            exit(1);
        }

        //existing master schema for application
        con->setSchema("passwordmanager");

        //select all rows from masterUser
        pstmt = con->prepareStatement("INSERT INTO accounts(email, username, password, url, application, userID) VALUES(?,?,?,?,?,?)");

        pstmt->setString(1, email);
        pstmt->setString(2, username);
        pstmt->setString(3, password);
        pstmt->setString(4, url);
        pstmt->setString(5, app);
        pstmt->setInt(6, userID);
        pstmt->execute();

        delete pstmt;
        delete con;

        return true;
	}
	bool deleteAccount(int id)
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



        //sql variables
        sql::Driver* driver;
        sql::Connection* con;
        sql::PreparedStatement* pstmt;
        sql::ResultSet* result;

        //storage variables
        int userID;
        std::string masterUser;
        std::string masterPass;

        //try to get connection to sql server
        try
        {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
        }

        catch (sql::SQLException e)
        {
            std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
            system("pause");
            exit(1);
        }

        //existing master schema for application
        con->setSchema("passwordmanager");

        //select all rows from masterUser
        pstmt = con->prepareStatement("DELETE FROM accounts WHERE id = ?;");

        pstmt->setInt(1, id);

        result = pstmt->executeQuery();


        delete result;
        delete pstmt;
        delete con;

        return true;
	}
}