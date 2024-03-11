#pragma once
#include <string>


namespace passwordManager
{

	class User
	{
	public:
		User(std::string name, std::string pass, int id)
		{
			username = name;
			password = pass;
			userID = id;

		}
		int getUserID() { return userID; }
		std::string getUsername() { return username; }
	private:
		std::string username;
		std::string password;
		int userID;
	};

	constexpr int maxAttempts = 5;
	

	User checkMasterLogin(std::string inputU, std::string inputP);

	bool createMasterLogin(std::string inputU, std::string inputP);

	std::string checkPassword(std::string password);

}

