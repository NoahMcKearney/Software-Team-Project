#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_Tic_Tac_Toe.h"
#include "Player.h"
#include "Computer.h"
#include "gamePlay.h"

Player User("");
Computer Opponent("O");
GamePlay board("0");

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

// board buttons
void Tic_Tac_Toe::on_FirstpushButton_clicked()
{
	ui.FirstpushButton->setText(QString::fromStdString(User.getSymbol()));
	board.updateBoardProgress(0, 0, User.getSymbol());
	Opponent.computerTurn();
}

void Tic_Tac_Toe::on_SecondpushButton_clicked()
{

}
void Tic_Tac_Toe::on_ThirdpushButton_clicked()
{

}
void Tic_Tac_Toe::on_FourthpushButton_clicked()
{

}
void Tic_Tac_Toe::on_FifthpushButton_clicked()
{

}
void Tic_Tac_Toe::on_SixthpushButton_clicked()
{

}
void Tic_Tac_Toe::on_SeventhpushButton_clicked()
{


}
void Tic_Tac_Toe::on_EighthpushButton_clicked()
{


}
void Tic_Tac_Toe::on_NinthpushButton_clicked()
{


}