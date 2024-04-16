#pragma once
#include <string>


namespace database
{
	//user class to define sql masteruser
	class User
	{
	public:
		User(std::string name, std::string pass, std::string hash, int id)
		{
			username = name;
			password = pass;
			gameHash = hash;
			userID = id;
		}
		int getUserID() { return userID; }
		std::string getUsername() { return username; }
		std::string getGameHash() { return gameHash; }
	private:
		std::string username;
		std::string password;
		std::string gameHash;
		int userID;
	};
	
	/*
	* check inputted username and password with sql masterusers
	* check if login exists in sql database
	* return a User corresponding to data in db or empty user
	*/
	User checkMasterLogin(std::string inputU, std::string inputP);

	/*
	* create new login within SQL database using inputU, inputP, and a generatedPass
	* returns bool of whether successful
	*/
	bool createMasterLogin(std::string inputU, std::string inputP, std::string generatedPass);

	//simply uses input username to get gamehash from user database
	std::string getGameHashFromDB(std::string inputU);

	//check whether a provided password abides by set rules
	std::string checkPassword(std::string password);

}

