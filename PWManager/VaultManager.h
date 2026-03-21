#pragma once
#include <string>

namespace controllers
{
    // A clean data transfer object to move UI data around
    struct AccountData {
        std::string email;
        std::string username;
        std::string password;
        std::string url;
        std::string application;
    };

    class VaultManager
    {
    public:
        // Takes raw UI data handles encryption and saves to the DB
        static bool saveNewAccount(int userId, AccountData data, std::string gameHash);

        // Takes the encrypted DB string and the game hash returns plaintext password
        static std::string unlockPassword(std::string encryptedPassword, std::string gameHash);

    private:
        // Helper function to format the OpenSSL 32-byte key
        static std::string formatAesKey(std::string rawHash);
    };
}