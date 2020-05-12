#include "stdafx.h"
#include "GamePicker.h"
#include "tic_tac_toe.h"
#include "hangman.h"
#include "rockpaperscissors.h"

GamePicker::GamePicker(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void GamePicker::on_ticTacToeButton_clicked()
{
    Tic_Tac_Toe dialog(this);

    dialog.exec();
}

void GamePicker::on_hangmanButton_clicked() {
        Hangman dialogTwo(this);
        dialogTwo.exec();
}

void GamePicker::on_rockPaperScissors_clicked(){
        rockPaperScissors dialogThree(this);
        dialogThree.exec();
}

void GamePicker::on_quitButton_clicked()
{
        this->close();
}
