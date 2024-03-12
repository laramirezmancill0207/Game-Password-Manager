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
	

private slots:
	void closeEvent(QCloseEvent* event);
	void on_addAccount_clicked();
	void showEvent(QShowEvent* event);
	void refreshTable();

private:
	 
};
