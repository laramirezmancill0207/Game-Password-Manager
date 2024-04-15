# Game Password Manager
 a password manager which stores user logins
 This software allows a user to create and enter passwords using normal text
 It also allows for the use of games such as chess/checkers to enter passwords
 Ths is similar to how you can enter passwords using a pattern on a smartphone
 
 Initial Login/Sign Up Window:
![pwman](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/efdb438c-e945-4bf6-9d53-21ad47c5a7d1)


 
 Main Menu:
 ![Untitled](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/998ab8d0-fc98-4de3-8c1a-4f024930d45f)
 
 This software is developed in C++ using qt for the frontend
 uses MySQL database server to store data
 The idea is to allow users to create passwords in game environments like chess/checkers etc.
 User data is stored using bcrypt encryption methods

Visual studio and mysql server must be properly set up in order to be able to run this program
libraries that must be installed on VS: QMYSQL connector, qopengl, qt

Install Instructions:
openSSL win64 may need to be installed 
download at https://www.openssl.org/

must install qmysql dlls as well as libmysql dll
easy install: https://github.com/thecodemonkey86/qt_mysql_driver

bcrypt encryption using wrapper by trusch
must download https://github.com/trusch/libbcrypt/tree/master

may need to add opengl32.lib to vs linker
