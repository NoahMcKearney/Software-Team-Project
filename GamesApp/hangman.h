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
	// Method makes buttons clickable or not:
	void enableDisableButtons(bool enableButtons);
	void beginNewGame();
	void displayWord();
private slots:
	void letterPressed();
	// Resets the game:
	void on_resetButton_clicked();
	// Displays the word when the user presses the Reveal button:
	void on_revealButton_clicked();
	// Quits the hangman game and returns user back to main form:
	void on_quitButton_clicked();
};
