#pragma once
#include <string>


namespace passwordManager
{

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

	constexpr int maxAttempts = 5;
	

	User checkMasterLogin(std::string inputU, std::string inputP);

	bool createMasterLogin(std::string inputU, std::string inputP, std::string generatedPass);

	std::string getGameHash(int id);

	std::string checkPassword(std::string password);

}

