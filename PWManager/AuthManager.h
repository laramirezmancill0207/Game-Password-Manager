#pragma once
#include <string>

namespace controllers
{
    // A struct to pass authentication data back to the UI
    struct AuthResult {
        bool success;
        std::string message;
        int userId;
        std::string gameHash;
    };

    class AuthManager
    {
    public:
        // Handles login validation and fetches user data
        static AuthResult attemptLogin(std::string username, std::string password);

        // Handles regex rules, validation, and database registration
        static AuthResult registerAccount(std::string username, std::string password, std::string gameHash);
    };
}