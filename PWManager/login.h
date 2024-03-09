#pragma once
#include <string>
#include <iostream>
#include <fstream>

namespace passwordManager
{

	constexpr int maxAttempts = 5;
	

	bool checkMasterLogin(std::string inputU, std::string inputP);

	bool createMasterLogin(std::string inputU, std::string inputP);

	std::string checkPassword(std::string password);

}

