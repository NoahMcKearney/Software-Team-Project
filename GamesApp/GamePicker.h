#pragma once

#include <QtWidgets/QWidget>
#include "ui_GamePicker.h"

// Main screen that allows user to select which game to play...
class GamePicker : public QWidget
{
	Q_OBJECT

public:
	GamePicker(QWidget *parent = Q_NULLPTR);

private:
	Ui::GamePickerClass ui;
private slots:
	void on_ticTacToeButton_clicked();
    void on_rockPaperScissorsButton_clicked();
	void on_quitButton_clicked();
	void on_hangmanButton_clicked();

};
