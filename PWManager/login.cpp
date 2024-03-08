#include "login.h"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


namespace passwordManager 
{
    bool checkMasterLogin(std::string inputU, std::string inputP)
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
        pstmt = con->prepareStatement("SELECT * FROM masteruser WHERE username = ?;");

        pstmt->setString(1, inputU);

        result = pstmt->executeQuery();

        //convert result to get login info
        while (result->next())
        {
            userID = result->getInt(1);
            masterUser = result->getString("username").c_str();
            masterPass = result->getString("password").c_str();
        }


        delete result;
        delete pstmt;
        delete con;

        //check if sql matches user input
		if (inputU == masterUser && inputP == masterPass)
		{
			return true;
		}
		return false;
	}
}