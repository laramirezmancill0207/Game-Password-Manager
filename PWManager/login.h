#pragma once
#include <string>
#include <iostream>

namespace passwordManager
{

	constexpr int maxAttempts = 5;
	

	bool checkMasterLogin(std::string inputU, std::string inputP);



}

