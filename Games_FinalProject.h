#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Games_FinalProject.h"

class Games_FinalProject : public QMainWindow
{
	Q_OBJECT

public:
	Games_FinalProject(QWidget *parent = Q_NULLPTR);

private:
	Ui::Games_FinalProjectClass ui;
};
