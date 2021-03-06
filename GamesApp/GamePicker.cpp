#include "stdafx.h"
#include "GamePicker.h"
#include "tic_tac_toe_game.h"
#include "hangman.h"
#include "rockpaperscissorsui.h"

GamePicker::GamePicker(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

// Buttons for main form
void GamePicker::on_ticTacToeButton_clicked()
{
    Tic_Tac_Toe dialog(this);

    dialog.exec();
}

void GamePicker::on_hangmanButton_clicked() {
	Hangman dialogTwo(this);
	dialogTwo.exec();
}

void GamePicker::on_rockPaperScissorsButton_clicked(){
	rockPaperScissorsUI dialogThree(this);
	dialogThree.exec();
}

void GamePicker::on_quitButton_clicked()
{
	this->close();
}
