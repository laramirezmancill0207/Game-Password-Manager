#include "VaultManager.h"
#include "crypto.h"
#include "accounts.h"
#include <stdexcept>

namespace controllers
{
    std::string VaultManager::formatAesKey(std::string rawHash) {
        std::string aesKey = rawHash.substr(0, 32);
        if (aesKey.length() < 32) aesKey.append(32 - aesKey.length(), '0');
        return aesKey;
    }

    bool VaultManager::saveNewAccount(int userId, AccountData data, std::string gameHash) {
        // Safety Check
        if (gameHash.empty() || data.password.empty()) {
            return false;
        }

        // Encrypt
        std::string aesKey = formatAesKey(gameHash);
        std::string encryptedPassword = crypto::encryptAES(data.password, aesKey);

        // Database Save
        return database::createAccount(userId, data.email, data.username, encryptedPassword, data.url, data.application);
    }

    std::string VaultManager::unlockPassword(std::string encryptedPassword, std::string gameHash) {
        if (gameHash.empty() || encryptedPassword.empty()) {
            return "";
        }

        std::string aesKey = formatAesKey(gameHash);

        try {
            // Returns the plaintext password if the gameHash is correct
            return crypto::decryptAES(encryptedPassword, aesKey);
        }
        catch (...) {
            // If the user played the wrong chess moves the decryption fails.
            return "";
        }
    }
}