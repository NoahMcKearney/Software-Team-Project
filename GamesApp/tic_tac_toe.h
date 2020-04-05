#pragma once

#include <QWidget>
#include "ui_tic_tac_toe.h"

class Tic_Tac_Toe : public QWidget
{
	Q_OBJECT

public:
	Tic_Tac_Toe(QWidget *parent = Q_NULLPTR);
	~Tic_Tac_Toe();

private:
	Ui::Tic_Tac_Toe ui;
};
