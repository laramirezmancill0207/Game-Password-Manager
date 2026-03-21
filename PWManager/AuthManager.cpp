#include "AuthManager.h"
#include "login.h"
#include "bcrypt/BCrypt.hpp"
#include <regex>

namespace controllers
{
    AuthResult AuthManager::attemptLogin(std::string username, std::string password)
    {
        if (username.empty() || password.empty()) {
            return { false, "Please enter both a username and password", -1, "" };
        }

        // Get the record from the database
        database::User user = database::getUserByUsername(username);

        if (user.getUsername().empty() || user.getUserID() == -1) {
            return { false, "Username does not exist", -1, "" };
        }

        // Validate the raw password against the database hash
        if (!BCrypt::validatePassword(password, user.getPassword())) {
            return { false, "Incorrect password", -1, "" };
        }

        return { true, "Login successful", user.getUserID(), user.getGameHash() };
    }

    AuthResult AuthManager::registerAccount(std::string username, std::string password, std::string gameHash)
    {
        if (password.length() < 8) {
            return { false, "Password must be 8 characters or more", -1, "" };
        }

        std::regex rules("^(?=.*[0-9])(?=.*[a-z])(?=.*[A-Z])(?!.* ).{8,}$");
        if (!std::regex_match(password, rules)) {
            return { false, "Password rules: at least one lower case, upper case, digit. No spaces.", -1, "" };
        }

        // Hash the password here
        std::string hashedPw = BCrypt::generateHash(password);

        bool created = database::createMasterLogin(username, hashedPw, gameHash);

        if (created) {
            return { true, "Login successfully created", -1, "" };
        }

        return { false, "Login was not able to be created. Username may already exist.", -1, "" };
    }
}