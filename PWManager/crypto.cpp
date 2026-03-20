#include "crypto.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <vector>
#include <stdexcept>
#include <QByteArray>

namespace crypto {

    std::string encryptAES(const std::string& plaintext, const std::string& key) {
        if (key.length() < 32) {
            throw std::invalid_argument("Key must be at least 32 bytes for AES-256");
        }

        // Generate a random 16-byte IV (Initialization Vector)
        unsigned char iv[16];
        if (!RAND_bytes(iv, sizeof(iv))) {
            throw std::runtime_error("Failed to generate random IV");
        }

        // Setup OpenSSL EVP Context
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        if (!ctx) throw std::runtime_error("Failed to create EVP context");

        // Initialize encryption operation with AES-256-CBC
        if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL,
            reinterpret_cast<const unsigned char*>(key.data()), iv)) {
            EVP_CIPHER_CTX_free(ctx);
            throw std::runtime_error("Encryption init failed");
        }

        // Provide the message to be encrypted
        std::vector<unsigned char> ciphertext(plaintext.length() + EVP_MAX_BLOCK_LENGTH);
        int len = 0;
        int ciphertext_len = 0;

        if (1 != EVP_EncryptUpdate(ctx, ciphertext.data(), &len,
            reinterpret_cast<const unsigned char*>(plaintext.data()), plaintext.length())) {
            EVP_CIPHER_CTX_free(ctx);
            throw std::runtime_error("Encryption update failed");
        }
        ciphertext_len = len;

        // Finalize the encryption
        if (1 != EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len)) {
            EVP_CIPHER_CTX_free(ctx);
            throw std::runtime_error("Encryption final failed");
        }
        ciphertext_len += len;
        EVP_CIPHER_CTX_free(ctx);

        // Combine IV + Ciphertext so we can decrypt it later
        QByteArray combined;
        combined.append(reinterpret_cast<const char*>(iv), sizeof(iv));
        combined.append(reinterpret_cast<const char*>(ciphertext.data()), ciphertext_len);

        // Return as a safe Base64 string for MySQL storage
        return combined.toBase64().toStdString();
    }

    std::string decryptAES(const std::string& ciphertextBase64, const std::string& key) {
        if (key.length() < 32) {
            throw std::invalid_argument("Key must be at least 32 bytes for AES-256");
        }

        // Decode the Base64 string back into raw bytes
        QByteArray combined = QByteArray::fromBase64(QByteArray::fromStdString(ciphertextBase64));

        if (combined.size() < 16) {
            return ""; // Invalid ciphertext
        }

        // Extract the IV (first 16 bytes) and the actual ciphertext
        const unsigned char* iv = reinterpret_cast<const unsigned char*>(combined.data());
        const unsigned char* ciphertext = reinterpret_cast<const unsigned char*>(combined.data() + 16);
        int ciphertext_len = combined.size() - 16;

        // Setup OpenSSL EVP Context
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
        if (!ctx) throw std::runtime_error("Failed to create EVP context");

        // Initialize decryption operation
        if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL,
            reinterpret_cast<const unsigned char*>(key.data()), iv)) {
            EVP_CIPHER_CTX_free(ctx);
            return ""; // Decryption failed
        }

        // Provide the message to be decrypted
        std::vector<unsigned char> plaintext(ciphertext_len + EVP_MAX_BLOCK_LENGTH);
        int len = 0;
        int plaintext_len = 0;

        if (1 != EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext, ciphertext_len)) {
            EVP_CIPHER_CTX_free(ctx);
            return "";
        }
        plaintext_len = len;

        // Finalize decryption (this checks the padding to ensure the key was correct)
        // If the user played the wrong chess moves, this step will fail
        if (1 != EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len)) {
            EVP_CIPHER_CTX_free(ctx);
            return ""; // Bad decrypt (wrong password/key!)
        }
        plaintext_len += len;
        EVP_CIPHER_CTX_free(ctx);

        return std::string(reinterpret_cast<char*>(plaintext.data()), plaintext_len);
    }
}