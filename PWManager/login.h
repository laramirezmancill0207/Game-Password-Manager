#pragma once
#include <string>

namespace database
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
		std::string getPassword() { return password; }
		std::string getGameHash() { return gameHash; }
	private:
		std::string username;
		std::string password;
		std::string gameHash;
		int userID;
	};

	// Simply retrieves a user record from the DB by username. Returns empty User if not found.
	User getUserByUsername(std::string inputU);

	// Inserts a new user into the database. The password must ALREADY be hashed before passing it here.
	bool createMasterLogin(std::string inputU, std::string hashedPassword, std::string generatedPass);

	// Simply uses input username to get gamehash from user database
	std::string getGameHashFromDB(std::string inputU);
}