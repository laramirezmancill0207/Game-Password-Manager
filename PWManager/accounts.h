#pragma once
#include <string>

namespace passwordManager
{
	bool createAccount(int userID, std::string email, std::string username, std::string password, std::string url, std::string app);
	bool deleteAccount(int id);
}
