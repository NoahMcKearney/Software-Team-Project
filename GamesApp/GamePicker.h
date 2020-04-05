#pragma once

#include <QtWidgets/QWidget>
#include "ui_GamePicker.h"

class GamePicker : public QWidget
{
	Q_OBJECT

public:
	GamePicker(QWidget *parent = Q_NULLPTR);

private:
	Ui::GamePickerClass ui;
private slots:
	void on_ticTacToeButton_clicked();
	void on_memoryButton_clicked();
	void on_quitButton_clicked();

};