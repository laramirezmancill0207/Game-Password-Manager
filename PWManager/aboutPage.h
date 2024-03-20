#pragma once

#include <QDialog>
#include "ui_aboutPage.h"

class aboutPage : public QDialog
{
	Q_OBJECT

public:
	aboutPage(QWidget *parent = nullptr);
	~aboutPage();

private:
	Ui::aboutPageClass ui;
};
