# Game Password Manager
 a password manager that stores user logins
 This software allows a user to create and enter passwords using normal text
 It also allows for the use of games such as chess/checkers to enter passwords
 This is similar to how you can enter passwords using a pattern on a smartphone
 
 Initial Login/Sign Up Window:
![pwman](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/e3cdf348-6953-4525-98f8-f11b6f1c7f73)



 
 Main Menu:
![mainmenu](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/a354aceb-af55-4583-a04f-3f7e992c6492)




Password Generation Screen:
![menu](https://github.com/laramirezmancill0207/Game-Password-Manager/assets/90569222/aaa2c2dc-22cf-4d87-b02c-246fb7f740c6)

 
 This software is developed in C++ using qt for the frontend
 uses MySQL database server to store data
 The idea is to allow users to create passwords in game environments like chess/checkers etc.
 User data is stored using bcrypt encryption methods

Visual studio and mysql server must be properly set up in order to be able to run this program
libraries that must be installed on VS: QMYSQL connector, qt

Install Instructions:
openSSL win64 may need to be installed 
download at https://www.openssl.org/

must install qmysql dlls as well as libmysql dll
easy install: https://github.com/thecodemonkey86/qt_mysql_driver

bcrypt encryption using wrapper by trusch
must download https://github.com/trusch/libbcrypt/tree/master
