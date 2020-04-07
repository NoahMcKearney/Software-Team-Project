#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_Tic_Tac_Toe.h"
#include "Player.h"
#include "Computer.h"

Player User("X");
Computer Opponent("O");

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void Tic_Tac_Toe::on_XChoicepushbutton_clicked()
{
	User.setSymbol("X");
	Opponent.setSymbol("O");
	ui.OChoicepushbutton->hide();
}

void Tic_Tac_Toe::on_OChoicepushbutton_clicked()
{
	User.setSymbol("O");
	Opponent.setSymbol("X");
	ui.XChoicepushbutton->hide();
}
