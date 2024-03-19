# Game Password Manager
 a password manager which stores user logins
 This software is developed in C++ using qt for the frontend
 uses MySQL database server to store data
 The idea is to allow users to create passwords in game environments like chess/checkers etc.
 User data is stored using bcrypt encryption methods

Visual studio and mysql server must be properly set up in order to be able to run this program
libraries that must be installed on VS: QMYSQL connector, glfw/opengl, qt

additional notes:
mysql schema : passwordmanager
mysql tables: masterUser, accounts

openSSL win64 may need to be installed

must install qmysql dlls as well as libmysql dll

bcrypt encryption using wrapper by trusch
must download https://github.com/trusch/libbcrypt/tree/master
