#pragma once
#include <QDialog>
#include "ui_hangman.h"

class Hangman : public QDialog, public Ui::hangman
{
	Q_OBJECT

public:
	Hangman(QWidget *parent = Q_NULLPTR);
	~Hangman();
private:
	Ui::hangman* ui;
	void enableDisableButtons(bool enableButtons);
	void beginNewGame();
	void displayWord();
private slots:
	void letterPressed();
	void on_resetButton_clicked();
	void on_revealButton_clicked();
	void on_quitButton_clicked();
};
