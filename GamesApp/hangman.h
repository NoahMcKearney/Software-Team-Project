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
	void updateUI(bool bGuessingWord);
	void displayWord();
	void beginNewGame();
private slots:
	void on_startButton_clicked();
	void letterPressed();
	void on_quitButton_clicked();
	void on_resetButton_clicked();
//	void on_revealButton_clicked();
};
