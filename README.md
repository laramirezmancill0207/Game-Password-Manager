# Gamified Password Manager

A secure, C++ desktop application that reimagines password generation and vault security. Instead of relying only on standard text passwords, this manager uses deterministic 2D game states (Chess & Checkers) to generate highly secure, cryptographic master keys. 

Similar to a smartphone lock pattern, you can play a sequence of moves on a virtual board to unlock your password vault and decrypt your saved credentials.

### Visual Showcase
| Login/Sign Up | Main Vault Dashboard | Game Generation Engine |
| :---: | :---: | :---: |
| ![pwman](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/54321b69-8a7e-4747-87a5-b157cbf86a5a) | ![mainmenu](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/51d8e95b-4a68-4fe7-ae4e-b04be4db0b2c) | ![menu](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/80d75caa-a385-443c-9db0-f11fd26053a4) |

---

## System Architecture & Key Features

This application was written using the **Model-View-Controller (MVC)** design pattern and the **Single Responsibility Principle**.

### 1. Headless C++ Game Engine (The Model)
* The core chess and checkers rules use pure C++ math (2D arrays and structs), which is independent of the Qt Graphics framework. 
* Uses deterministic integer logic, so the engine guarantees zero UI-driven memory leaks during board evaluation.
* Every move is tracked and compiled into a raw board state string, which is then passed through a **SHA-256** algorithm to generate a 32-byte master key which is also unique to each user.

### 2. Full-Stack Cryptography (The Controller)
* Integrated **OpenSSL** to securely encrypt and decrypt vault passwords in real-time. Plaintext passwords are never saved to the database or stored in memory longer than necessary.
* Master user logins are hashed and salted using BCrypt before database insertion, protecting against brute-force attacks.
* Dedicated `VaultManager` and `AuthManager` controllers handle all business logic, acting as the secure bridge between the UI and the SQL database.

### 3. Pure SQL Database (The Data Layer)
* Uses Qt's `QSqlDatabase` and pure SQL queries for all data retrieval and storage. (Using MySQL)
* The database only stores Base64 AES-encrypted payloads and BCrypt hashes.

---

## Technology Stack
* **Language:** C++17
* **Frontend GUI:** Qt 6 (Widgets, QGraphicsScene, QPainter)
* **Cryptography:** OpenSSL (AES/SHA), BCrypt
* **Database:** MySQL Server (QMYSQL Driver)
* **Architecture:** MVC, Headless Engine Design, Dependency Injection

---

## Installation & Build Instructions

**(Note that this is just one way to configure this project. The following instructions are for a Windows system with Visual Studio 2022 and QT.)**
To build and run this project locally, ensure you have **Visual Studio 2022** and **MySQL Server** properly installed on your system.

### Prerequisites
1. **Qt 6:** Install the Qt framework and the Visual Studio Qt extension.
2. **OpenSSL (Win64):** Download and configure OpenSSL for your build environment. [Download OpenSSL](https://www.openssl.org/)
3. **MySQL Connector:** Ensure you have the `qsqlmysql.dll` and `libmysql.dll` configured in your Qt SQL drivers directory. ([Setup Guide](https://github.com/thecodemonkey86/qt_mysql_driver))
4. **BCrypt Wrapper:** This project uses the C++ BCrypt wrapper by trusch. Ensure the headers are included. ([libbcrypt](https://github.com/trusch/libbcrypt/tree/master))

### Setup
1. Clone this repository.
2. Set up a local MySQL instance and update the `database.json` file in the project root with your database credentials (driver, host, user, password).
3. Build the solution using the `x64 Release` configuration in Visual Studio.