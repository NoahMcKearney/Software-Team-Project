#include <QtWidgets>
#include <QtCore>
#include <QtGui>

#include "stdafx.h"
#include "tic_tac_toe.h"
#include "ui_Tic_Tac_Toe.h"
#include "Player.h"
#include "Computer.h"

const int size = 9;

std::vector<std::string> BoardVector(size);

int iButtonPressed = 0, iCountComputerIndex = 0, iCounterUserIndex = 0;
Player User("");
Computer Opponent("");

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	ui.setupUi(this);
	disableButton();
}

void Tic_Tac_Toe::updateUI(int ibutton)
{
	switch (ibutton)
	{
	case 1:

		ui.FirstpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.FirstpushButton->setDisabled(true);
		ui.FirstpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 2:
		ui.SecondpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.SecondpushButton->setDisabled(true);
		ui.SecondpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 3:
		ui.ThirdpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.ThirdpushButton->setDisabled(true);
		ui.ThirdpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 4:
		ui.FourthpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.FourthpushButton->setDisabled(true);
		ui.FourthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 5:
		ui.FifthpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.FifthpushButton->setDisabled(true);
		ui.FifthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 6:
		ui.SixthpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.SixthpushButton->setDisabled(true);
		ui.SixthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 7:
		ui.SeventhpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.SeventhpushButton->setDisabled(true);
		ui.SeventhpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 8:
		ui.EighthpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.EighthpushButton->setDisabled(true);
		ui.EighthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	case 9:
		ui.NinthpushButton->setStyleSheet(QString::fromStdString(Opponent.getFontColor()));
		ui.NinthpushButton->setDisabled(true);
		ui.NinthpushButton->setText(QString::fromStdString(Opponent.getSymbol()));
		break;
	}
}

void Tic_Tac_Toe::on_XChoicepushbutton_clicked()
{
	enableButton();
	User.setSymbol("X");
	Opponent.setSymbol("O");
	ui.OChoicepushbutton->hide();
	ui.winningLabel->setText("");
}

void Tic_Tac_Toe::on_OChoicepushbutton_clicked()
{
	enableButton();
	User.setSymbol("O");
	Opponent.setSymbol("X");
	ui.XChoicepushbutton->hide();
	ui.winningLabel->setText("");
}

// board buttons
void Tic_Tac_Toe::on_FirstpushButton_clicked()
{
	ui.FirstpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.FirstpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FirstpushButton->setDisabled(true);

	iButtonPressed = 1;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}

void Tic_Tac_Toe::on_SecondpushButton_clicked()
{
	ui.SecondpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.SecondpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SecondpushButton->setDisabled(true);

	iButtonPressed = 2;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_ThirdpushButton_clicked()
{
	ui.ThirdpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.ThirdpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.ThirdpushButton->setDisabled(true);

	iButtonPressed = 3;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_FourthpushButton_clicked()
{
	ui.FourthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.FourthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FourthpushButton->setDisabled(true);

	iButtonPressed = 4;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_FifthpushButton_clicked()
{
	ui.FifthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.FifthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FifthpushButton->setDisabled(true);

	iButtonPressed = 5;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_SixthpushButton_clicked()
{
	ui.SixthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.SixthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SixthpushButton->setDisabled(true);

	iButtonPressed = 6;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_SeventhpushButton_clicked()
{
	ui.SeventhpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.SeventhpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SeventhpushButton->setDisabled(true);

	iButtonPressed = 7;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_EighthpushButton_clicked()
{
	ui.EighthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.EighthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.EighthpushButton->setDisabled(true);

	iButtonPressed = 8;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}
void Tic_Tac_Toe::on_NinthpushButton_clicked()
{
	ui.NinthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	ui.NinthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.NinthpushButton->setDisabled(true);

	iButtonPressed = 9;
	updateBoard(iButtonPressed - 1);
	computerTurn();
	winnerCheck();
}

void Tic_Tac_Toe::updateBoard(int iButtonIndex)
{
	BoardVector[iButtonIndex] = User.getSymbol();
	iCounterUserIndex++;
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
	std::string Button3 = BoardVector[2];
	std::string Button4 = BoardVector[3];
	std::string Button5 = BoardVector[4];
	std::string Button6 = BoardVector[5];
	std::string Button7 = BoardVector[6];
	std::string Button8 = BoardVector[7];
	std::string Button9 = BoardVector[8];
	
	// Top row 
	if (Button1 == Button2 && Button2 == Button3)
	{
		// displays who won
		if (Button1 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if (Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// middle row
	else if ((Button4 == Button5 && Button4 == Button6))
	{
		// displays who won
		if (Button4 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if (Button4 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// bottom row
	else if ((Button7 == Button8 && Button7 == Button9))
	{
		// displays who won
		if (Button7 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
		}
		else if (Button7 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// first column
	else if ((Button1 == Button4 && Button1 == Button7))
	{
		// displays who won
		if (Button1 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if(Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// second column
	else if ((Button2 == Button5 && Button2 == Button8))
	{
		// displays who won
		if (Button2 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if(Button2 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// third column
	else if ((Button3 == Button6 && Button3 == Button9))
	{
		// displays who won
		if (Button3 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if (Button3 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// left to right diagonal
	else if ((Button1 == Button5 && Button1 == Button9))
	{
		// displays who won
		if (Button1 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
		}
		else if (Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// right to left diagonal
	else if ((Button3 == Button5 && Button3 == Button7))
	{
		// displays who won
		if (Button3 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
		}
		else if (Button3 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
		}
	}
	// No winner
	else if (iCountComputerIndex == 4 && iCounterUserIndex == 5)
	{
		ui.winningLabel->setText("No winner.");
	}
}

// close and reset vector
void Tic_Tac_Toe::on_exitButton_clicked()
{
	for (int iCounter = 0; iCounter < BoardVector.size(); iCounter++)
	{
		BoardVector[iCounter] = "";
	}
	iCountComputerIndex = 0;
	iCounterUserIndex = 0;
	User.setSymbol("");
	Opponent.setSymbol("");
	close();
}

void Tic_Tac_Toe::disableButton()
{
	ui.FirstpushButton->setDisabled(true);
	ui.SecondpushButton->setDisabled(true);
	ui.ThirdpushButton->setDisabled(true);
	ui.FourthpushButton->setDisabled(true);
	ui.FifthpushButton->setDisabled(true);
	ui.SixthpushButton->setDisabled(true);
	ui.SeventhpushButton->setDisabled(true);
	ui.EighthpushButton->setDisabled(true);
	ui.NinthpushButton->setDisabled(true);
}

void Tic_Tac_Toe::enableButton()
{
	ui.FirstpushButton->setDisabled(false);
	ui.SecondpushButton->setDisabled(false);
	ui.ThirdpushButton->setDisabled(false);
	ui.FourthpushButton->setDisabled(false);
	ui.FifthpushButton->setDisabled(false);
	ui.SixthpushButton->setDisabled(false);
	ui.SeventhpushButton->setDisabled(false);
	ui.EighthpushButton->setDisabled(false);
	ui.NinthpushButton->setDisabled(false);
}

