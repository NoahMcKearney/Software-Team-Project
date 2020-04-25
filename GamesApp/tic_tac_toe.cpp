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
bool gameEnds = false;
Player User("");
Computer Opponent("");

Tic_Tac_Toe::Tic_Tac_Toe(QWidget *parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	ui.setupUi(this);
	// disables board's buttons
	disableButton();
}

// Adds computer symbol to the board
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
	// set symbols to Player and Computer class
	User.setSymbol("X");
	Opponent.setSymbol("O");
	ui.OChoicepushbutton->hide();
	ui.winningLabel->setText("Play the game, you vs. the computer!");
	ui.chooseLabel->setText("Your symbol is a X!");
}

void Tic_Tac_Toe::on_OChoicepushbutton_clicked()
{
	enableButton();
	// set symbols to Player and Computer class
	User.setSymbol("O");
	Opponent.setSymbol("X");
	ui.XChoicepushbutton->hide();
	ui.winningLabel->setText("Play the game, you vs. the computer!");
	ui.chooseLabel->setText("Your symbol is a O!");
}

// Board:
void Tic_Tac_Toe::on_FirstpushButton_clicked()
{
	// set font color based on symbol
	ui.FirstpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.FirstpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FirstpushButton->setDisabled(true);

	iButtonPressed = 1;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}

void Tic_Tac_Toe::on_SecondpushButton_clicked()
{
	// set font color based on symbol 
	ui.SecondpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.SecondpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SecondpushButton->setDisabled(true);

	iButtonPressed = 2;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_ThirdpushButton_clicked()
{
	// set font color based on symbol 
	ui.ThirdpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.ThirdpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.ThirdpushButton->setDisabled(true);

	iButtonPressed = 3;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_FourthpushButton_clicked()
{
	// set font color based on symbol
	ui.FourthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.FourthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FourthpushButton->setDisabled(true);

	iButtonPressed = 4;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_FifthpushButton_clicked()
{
	// set font color based on symbol
	ui.FifthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.FifthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.FifthpushButton->setDisabled(true);

	iButtonPressed = 5;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_SixthpushButton_clicked()
{
	// set font color based on symbol
	ui.SixthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.SixthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SixthpushButton->setDisabled(true);

	iButtonPressed = 6;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_SeventhpushButton_clicked()
{
	// set font color based on symbol
	ui.SeventhpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.SeventhpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.SeventhpushButton->setDisabled(true);

	iButtonPressed = 7;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_EighthpushButton_clicked()
{
	// set font color based on symbol
	ui.EighthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.EighthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.EighthpushButton->setDisabled(true);

	iButtonPressed = 8;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}
void Tic_Tac_Toe::on_NinthpushButton_clicked()
{
	// set font color based on symbol
	ui.NinthpushButton->setStyleSheet(QString::fromStdString(User.getFontColor()));
	// write user's symbol to button
	ui.NinthpushButton->setText(QString::fromStdString(User.getSymbol()));
	ui.NinthpushButton->setDisabled(true);

	iButtonPressed = 9;
	updateBoard(iButtonPressed - 1);
	gameEnds = winnerCheck();
	// Game continues:
	if (gameEnds == false)
	{
		computerTurn();
		winnerCheck();
	}
}

// update BoardVector with user symbol
void Tic_Tac_Toe::updateBoard(int iButtonIndex)
{
	BoardVector[iButtonIndex] = User.getSymbol();
	iCounterUserIndex++;
}

// Switch turns
void Tic_Tac_Toe::computerTurn()
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

	bool bSpotTaken = false;

	while (!bSpotTaken)
	{		
		// if true, then computer stops playing
		if (iCountComputerIndex == 4)
		{
			bSpotTaken = true;
		}

		// Computer checks for best move based on computer's symbol
		// Top row 
		else if (Button1 == Opponent.getSymbol() && Button2 == Opponent.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Top row 
		else if ((Button1 == Opponent.getSymbol() && Button3 == Opponent.getSymbol()))
		{
			// check button 2, index of 1:
			if ((Opponent.getSymbol() == BoardVector[1]) || (User.getSymbol() == BoardVector[1]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 2 
				updateUI(2);
				BoardVector[1] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Top row 
		else if (Button2 == Opponent.getSymbol() && Button3 == Opponent.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1 
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// Middle row
		else if (Button4 == Opponent.getSymbol() && Button5 == Opponent.getSymbol())
		{
			// check button 6, index of 5:
			if ((Opponent.getSymbol() == BoardVector[5]) || (User.getSymbol() == BoardVector[5]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 6 
				updateUI(6);
				BoardVector[5] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Middle row
		else if (Button4 == Opponent.getSymbol() && Button6 == Opponent.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5 
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}

		}
		// Middle row 
		else if (Button5 == Opponent.getSymbol() && Button6 == Opponent.getSymbol())
		{
			// check button 4, index of 3:
			if ((Opponent.getSymbol() == BoardVector[3]) || (User.getSymbol() == BoardVector[3]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 4
				updateUI(4);
				BoardVector[3] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// bottom row
		else if (Button7 == Opponent.getSymbol() && Button8 == Opponent.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
				// places computer's symbol on button 9 
				updateUI(9);
			BoardVector[8] = Opponent.getSymbol();
			bSpotTaken = true;
			iCountComputerIndex++;
		}
		// bottom row
		else if (Button8 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7 
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// bottom row 
		else if (Button7 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 8, index of 7:
			if ((Opponent.getSymbol() == BoardVector[7]) || (User.getSymbol() == BoardVector[7]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 8
				updateUI(8);
				BoardVector[7] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// first column
		else if (Button1 == Opponent.getSymbol() && Button4 == Opponent.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// first column
		else if (Button4 == Opponent.getSymbol() && Button7 == Opponent.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// first column
		else if (Button1 == Opponent.getSymbol() && Button7 == Opponent.getSymbol())
		{
			// check button 4, index of 3:
			if ((Opponent.getSymbol() == BoardVector[3]) || (User.getSymbol() == BoardVector[3]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 4
				updateUI(4);
				BoardVector[3] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// second column
		else if (Button2 == Opponent.getSymbol() && Button5 == Opponent.getSymbol())
		{
			// check button 8, index of 7:
			if ((Opponent.getSymbol() == BoardVector[7]) || (User.getSymbol() == BoardVector[7]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 8
				updateUI(8);
				BoardVector[7] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// second column
		else if (Button5 == Opponent.getSymbol() && Button8 == Opponent.getSymbol())
		{
			// check button 2, index of 1:
			if ((Opponent.getSymbol() == BoardVector[1]) || (User.getSymbol() == BoardVector[1]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 2 
				updateUI(2);
				BoardVector[1] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// second column
		else if (Button2 == Opponent.getSymbol() && Button8 == Opponent.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// third column
		else if (Button3 == Opponent.getSymbol() && Button6 == Opponent.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 9 
				updateUI(9);
				BoardVector[8] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// third column
		else if (Button6 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// third column
		else if (Button3 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 6, index of 5:
			if ((Opponent.getSymbol() == BoardVector[5]) || (User.getSymbol() == BoardVector[5]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 6
				updateUI(6);
				BoardVector[5] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// left to right diagonal
		else if (Button1 == Opponent.getSymbol() && Button5 == Opponent.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 9
				updateUI(9);
				BoardVector[8] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button5 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button1 == Opponent.getSymbol() && Button9 == Opponent.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// right to left diagonal
		else if (Button3 == Opponent.getSymbol() && Button5 == Opponent.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button5 == Opponent.getSymbol() && Button7 == Opponent.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button3 == Opponent.getSymbol() && Button7 == Opponent.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5 
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// check to see if can intersect user
		// Top row 
		else if (Button1 == User.getSymbol() && Button2 == User.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Top row 
		else if ((Button1 == User.getSymbol() && Button3 == User.getSymbol()))
		{
			// check button 2, index of 1:
			if ((Opponent.getSymbol() == BoardVector[1]) || (User.getSymbol() == BoardVector[1]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 2 
				updateUI(2);
				BoardVector[1] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Top row 
		else if (Button2 == User.getSymbol() && Button3 == User.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1 
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// Middle row
		else if (Button4 == User.getSymbol() && Button5 == User.getSymbol())
		{
			// check button 6, index of 5:
			if ((Opponent.getSymbol() == BoardVector[5]) || (User.getSymbol() == BoardVector[5]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 6 
				updateUI(6);
				BoardVector[5] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Middle row
		else if (Button4 == User.getSymbol() && Button6 == User.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5 
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// Middle row 
		else if (Button5 == User.getSymbol() && Button6 == User.getSymbol())
		{
			// check button 4, index of 3:
			if ((Opponent.getSymbol() == BoardVector[3]) || (User.getSymbol() == BoardVector[3]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 4
				updateUI(4);
				BoardVector[3] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// bottom row
		else if (Button7 == User.getSymbol() && Button8 == User.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 9 
				updateUI(9);
				BoardVector[8] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// bottom row
		else if (Button8 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7 
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// bottom row 
		else if (Button7 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 8, index of 7:
			if ((Opponent.getSymbol() == BoardVector[7]) || (User.getSymbol() == BoardVector[7]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 8 
				updateUI(8);
				BoardVector[7] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// first column
		else if (Button1 == User.getSymbol() && Button4 == User.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7 
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// first column
		else if (Button4 == User.getSymbol() && Button7 == User.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// first column
		else if (Button1 == User.getSymbol() && Button7 == User.getSymbol())
		{
			// check button 4, index of 3:
			if ((Opponent.getSymbol() == BoardVector[3]) || (User.getSymbol() == BoardVector[3]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 4
				updateUI(4);
				BoardVector[3] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// second column
		else if (Button2 == User.getSymbol() && Button5 == User.getSymbol())
		{
			// check button 8, index of 7:
			if ((Opponent.getSymbol() == BoardVector[7]) || (User.getSymbol() == BoardVector[7]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 8 
				updateUI(8);
				BoardVector[7] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// second column
		else if (Button5 == User.getSymbol() && Button8 == User.getSymbol())
			{
			// check button 2, index of 1:
			if ((Opponent.getSymbol() == BoardVector[1]) || (User.getSymbol() == BoardVector[1]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 2 
				updateUI(2);
				BoardVector[1] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// second column
		else if (Button2 == User.getSymbol() && Button8 == User.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// third column
		else if (Button3 == User.getSymbol() && Button6 == User.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 9
				updateUI(9);
				BoardVector[8] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// third column
		else if (Button6 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// third column
		else if (Button3 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 6, index of 5:
			if ((Opponent.getSymbol() == BoardVector[5]) || (User.getSymbol() == BoardVector[5]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 6 
				updateUI(6);
				BoardVector[5] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// left to right diagonal
		else if (Button1 == User.getSymbol() && Button5 == User.getSymbol())
		{
			// check button 9, index of 8:
			if ((Opponent.getSymbol() == BoardVector[8]) || (User.getSymbol() == BoardVector[8]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 9 
				updateUI(9);
				BoardVector[8] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button5 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 1, index of 0:
			if ((Opponent.getSymbol() == BoardVector[0]) || (User.getSymbol() == BoardVector[0]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 1
				updateUI(1);
				BoardVector[0] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button1 == User.getSymbol() && Button9 == User.getSymbol())
		{
			// check button 5, index of 4:
			if ((Opponent.getSymbol() == BoardVector[4]) || (User.getSymbol() == BoardVector[4]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 5 
				updateUI(5);
				BoardVector[4] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		// right to left diagonal
		else if (Button3 == User.getSymbol() && Button5 == User.getSymbol())
		{
			// check button 7, index of 6:
			if ((Opponent.getSymbol() == BoardVector[6]) || (User.getSymbol() == BoardVector[6]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 7
				updateUI(7);
				BoardVector[6] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
		// left to right diagonal
		else if (Button5 == User.getSymbol() && Button7 == User.getSymbol())
		{
			// check button 3, index of 2:
			if ((Opponent.getSymbol() == BoardVector[2]) || (User.getSymbol() == BoardVector[2]))
			{
				bSpotTaken = false;
			}
			else
			{
				// places computer's symbol on button 3 
				updateUI(3);
				BoardVector[2] = Opponent.getSymbol();
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}

		if (bSpotTaken == false)
		{
			int index = rand() % 9 + 0;
			if ((Opponent.getSymbol() == BoardVector[index]) || (User.getSymbol() == BoardVector[index]))
			{
				bSpotTaken = false;
			}
			// if BoardVector with certain index is empty
			else if ((Opponent.getSymbol() != BoardVector[index]) || (User.getSymbol() != BoardVector[index]))
			{
				BoardVector[index] = Opponent.getSymbol();
				// add computer symbol to button on board
				updateUI(index + 1);
				bSpotTaken = true;
				iCountComputerIndex++;
			}
		}
	}
}

bool Tic_Tac_Toe::winnerCheck()
{
	// board's indexes equal to buttons' names
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button4 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
	}
	// bottom row
	else if ((Button7 == Button8 && Button7 == Button9))
	{
		// displays who won
		if (Button7 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button7 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if(Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if(Button2 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button3 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
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
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button1 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
	}
	// right to left diagonal
	else if ((Button3 == Button5 && Button3 == Button7))
	{
		// displays who won
		if (Button3 == User.getSymbol())
		{
			ui.winningLabel->setText("You are the winner!");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
		else if (Button3 == Opponent.getSymbol())
		{
			ui.winningLabel->setText("The computer is the winner.");
			disableButton();
			ui.XChoicepushbutton->setDisabled(true);
			ui.OChoicepushbutton->setDisabled(true);
			return true;
		}
	}
	// No winner
	else if (iCountComputerIndex == 4 && iCounterUserIndex == 5)
	{
		ui.winningLabel->setText("No winner.");
		ui.XChoicepushbutton->setDisabled(true);
		ui.OChoicepushbutton->setDisabled(true);
	}
	return false;
}

// exit form and reset vector
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

// board's button disable
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

// board's button enable
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