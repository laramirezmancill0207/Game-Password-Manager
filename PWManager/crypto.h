#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <openssl/evp.h>
#include <openssl/rand.h>

namespace crypto {
    // Encrypts plaintext using AES-256-CBC. 'key' must be 32 bytes (256 bits).
    std::string encryptAES(const std::string& plaintext, const std::string& key);

    // Decrypts ciphertext using AES-256-CBC.
    std::string decryptAES(const std::string& ciphertext, const std::string& key);
}

#endif // CRYPTO_H