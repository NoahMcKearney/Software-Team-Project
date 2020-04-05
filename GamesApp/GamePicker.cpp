#include "stdafx.h"
#include "GamePicker.h"
#include "tic_tac_toe.h"

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

void GamePicker::on_memoryButton_clicked()
{
}

void GamePicker::on_quitButton_clicked()
{
}
