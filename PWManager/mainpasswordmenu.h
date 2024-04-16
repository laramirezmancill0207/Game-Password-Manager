#pragma once

#include <QMainWindow>
#include "ui_mainpasswordmenu.h"
#include <QCloseEvent>

class mainpasswordmenu : public QMainWindow, public Ui::mainpasswordmenuClass
{
	Q_OBJECT

	
public:
	mainpasswordmenu(QWidget *parent = nullptr);
	~mainpasswordmenu();
	int getID();
	void setID(int userID);
	std::string getGameHash();
	void setGameHash(std::string gameH);
	

private slots:
	void closeEvent(QCloseEvent* event);
	void showEvent(QShowEvent* event);
	void on_addAccount_clicked();
	void on_deleteAccount_clicked();
	void refreshTable();
	void on_homeMenu_clicked();
	void on_gameMenu_clicked();
	void on_settingsMenu_clicked();
	void on_resetButton_clicked();
	void on_copyPassButton_clicked();
	void aboutMenu();

	void on_reset_clicked();
	void on_chess_clicked();
	void on_checkers_clicked();

private:
	int id;
	std::string gameHash;
};
