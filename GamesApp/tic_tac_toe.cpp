#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_Tic_Tac_Toe.h"
#include "Player.h"
#include "Computer.h"
#include "gamePlay.h"

const int size = 9;

std::vector<std::string> BoardVector(size);

int iButtonPressed = 0, iCountComputerIndex = 0;
Player User("");
Computer Opponent("");
GamePlay board("0");

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void Tic_Tac_Toe::updateUI(int ibutton)
{
	switch (ibutton)
	{
	case 1:
		ui.FirstpushButton->setDisabled(true);
		ui.FirstpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 2:
		ui.SecondpushButton->setDisabled(true);
		ui.SecondpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 3:
		ui.ThirdpushButton->setDisabled(true);
		ui.ThirdpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 4:
		ui.FourthpushButton->setDisabled(true);
		ui.FourthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 5:
		ui.FifthpushButton->setDisabled(true);
		ui.FifthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 6:
		ui.SixthpushButton->setDisabled(true);
		ui.SixthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 7:
		ui.SeventhpushButton->setDisabled(true);
		ui.SeventhpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 8:
		ui.EighthpushButton->setDisabled(true);
		ui.EighthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 9:
		ui.NinthpushButton->setDisabled(true);
		ui.NinthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	}
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
	ui.FirstpushButton->setDisabled(true);

	iButtonPressed = 1;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}

void Tic_Tac_Toe::on_SecondpushButton_clicked()
{
	ui.SecondpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SecondpushButton->setDisabled(true);

	iButtonPressed = 2;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_ThirdpushButton_clicked()
{
	ui.ThirdpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.ThirdpushButton->setDisabled(true);

	iButtonPressed = 3;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_FourthpushButton_clicked()
{
	ui.FourthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FourthpushButton->setDisabled(true);

	iButtonPressed = 4;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_FifthpushButton_clicked()
{
	ui.FifthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FifthpushButton->setDisabled(true);

	iButtonPressed = 5;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_SixthpushButton_clicked()
{
	ui.SixthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SixthpushButton->setDisabled(true);

	iButtonPressed = 6;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_SeventhpushButton_clicked()
{
	ui.SeventhpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SeventhpushButton->setDisabled(true);

	iButtonPressed = 7;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_EighthpushButton_clicked()
{
	ui.EighthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.EighthpushButton->setDisabled(true);

	iButtonPressed = 8;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}
void Tic_Tac_Toe::on_NinthpushButton_clicked()
{
	ui.NinthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.NinthpushButton->setDisabled(true);

	iButtonPressed = 9;
	updateBoard(iButtonPressed - 1);
	computerTurn();
}

void Tic_Tac_Toe::updateBoard(int iButtonIndex)
{
	BoardVector[iButtonIndex] = User.getSymbol();
}

void Tic_Tac_Toe::computerTurn()
{
	bool bSpotTaken = false;
	while (!bSpotTaken)
	{

		int index = rand() % 9 + 0, boardFill = 1;

		if (iCountComputerIndex == 4)
		{
			bSpotTaken = true;
		}
		else if ((Opponent.getSymbol() == BoardVector[index]) || (User.getSymbol() == BoardVector[index]))
		{
			bSpotTaken = false;
		}
		else 
		{
			BoardVector[index] = Opponent.getSymbol();
			updateUI(index+1);
			bSpotTaken = true;
			iCountComputerIndex++;
		}
	}
}

void Tic_Tac_Toe::winnerCheck()
{
	std::string Button1 = BoardVector[0];
	std::string Button2 = BoardVector[1];
	std::string indexZero = BoardVector[2];
	std::string indexZero = BoardVector[3];
	std::string indexZero = BoardVector[4];
	std::string indexZero = BoardVector[5];
	std::string indexZero = BoardVector[6];
	std::string indexZero = BoardVector[7];
	std::string indexZero = BoardVector[8];

}

