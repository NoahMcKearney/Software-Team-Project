#include "stdafx.h"
#include "hangman.h"
#include "CUser.h"

Hangman::Hangman(QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setupUi(this);
	// Upon opening game, calls below function and chooses word, sets up the screen for the user to start playing:
	beginNewGame();
	QPushButton* alphabetButtons[26];
	// Allows the alphabet buttons to be clickable:
	for (int counter = 0; counter < 26; ++counter) {
		QString buttonName = "buttonAlphabet" + QString::number(counter + 1);
		alphabetButtons[counter] = Hangman::findChild<QPushButton*>(buttonName);
		connect(alphabetButtons[counter], SIGNAL(released()), this, SLOT(letterPressed()));
	}
}

// Creates an instance of CUser class:
CUser userOne;

// Destructor:    
Hangman::~Hangman()
{
}

// This function makes buttons clickable by the user or disables them:
void Hangman::enableDisableButtons(bool enableButtons) {
	
	int buttonCounter = 1;
	if (enableButtons == true) {
		while (buttonCounter <= 26) {
			QString buttonNames = "buttonAlphabet" + QString::number(buttonCounter);
			Hangman::findChild<QPushButton*>(buttonNames)->setEnabled(true);
			Hangman::findChild<QPushButton*>(buttonNames)->setFlat(false);
			buttonCounter++;
		}
	}
	else {
		while (buttonCounter <= 26) {
			QString buttonNames = "buttonAlphabet" + QString::number(buttonCounter);
			Hangman::findChild<QPushButton*>(buttonNames)->setEnabled(false);
			buttonCounter++;
		}
	}
}

void Hangman::beginNewGame() {

	startMessageLabel->setText("Welcome to the Hangman, press any letter to begin!");
	// Finds the word for the user to guess:
	userOne.setWord();

	int numLinesButtonsCounter = 0;
	int buttonAphabetCounter = 1;
	// Builds the form before the user starts to play:
	while (numLinesButtonsCounter < 34) {
		if (numLinesButtonsCounter < 9) {
			QString lineNames = "line_" + QString::number(numLinesButtonsCounter);
			Hangman::findChild<QWidget*>(lineNames)->setVisible(false);
		}
		else {
			enableDisableButtons(true);
		}
		numLinesButtonsCounter++;
	}

	// Enables reveal and reset buttons:
	revealButton->setEnabled(true);
	resetButton->setEnabled(true);

	// Based upon the length of the word, lines appear on form showing how long the word is:
	int lengthWord = userOne.getWord().length();
	switch (lengthWord) {
	case 3:
		letterLines_0->setVisible(true);
		letterLines_1->setVisible(true);
		letterLines_2->setVisible(true);
		letterLines_3->setVisible(false);
		letterLines_4->setVisible(false);
		letterLines_5->setVisible(false);
		break;
	case 4:
		letterLines_0->setVisible(true);
		letterLines_1->setVisible(true);
		letterLines_2->setVisible(true);
		letterLines_3->setVisible(true);
		letterLines_4->setVisible(false);
		letterLines_5->setVisible(false);
		break;
	case 5:
		letterLines_0->setVisible(true);
		letterLines_1->setVisible(true);
		letterLines_2->setVisible(true);
		letterLines_3->setVisible(true);
		letterLines_4->setVisible(true);
		letterLines_5->setVisible(false);
		break;
	case 6:
		letterLines_0->setVisible(true);
		letterLines_1->setVisible(true);
		letterLines_2->setVisible(true);
		letterLines_3->setVisible(true);
		letterLines_4->setVisible(true);
		letterLines_5->setVisible(true);
		break;
	}
}

// Displays the word on the screen if user presses reveal button:
void Hangman::displayWord() {

	for (int counter3 = 0; counter3 <= userOne.getWord().length()-1; counter3++) {
		QString wordLetterLabelName = "labelLetter" + QString::number(counter3);
		Hangman::findChild<QLabel*>(wordLetterLabelName)->setText(QChar::fromLatin1((userOne.getWord().at(counter3))));
	}
}

void Hangman::letterPressed() {	

	QPushButton* button = (QPushButton*)sender();
	QString buttonName = button->objectName();
	int letterIndex = 0;
	QString valueOnButton = button->text();

	startMessageLabel->setText("");
	// Creates a vector and copies from created vector in checkWord() method:
	std::vector<int>letterIndexesInWrd = userOne.checkWord(valueOnButton.toStdString());

	// If letter is not matching any letter in the word, builds hangman:
	if (letterIndexesInWrd.size() == 0) {
		// Display line based upon how many guesses user gets wrong:
		userOne.guessWrongCounter();
		QString showLine = "line_" + QString::number(userOne.getAmountGuessesWrong()-1);
		Hangman::findChild<QWidget*>(showLine)->setVisible(true);

		// Lets the user know they have lost the game:
		if (userOne.getAmountGuessesWrong() == 9) {
			displayWord();
			infoLabel->setText("You Lose!");
			enableDisableButtons(false);
		}
	}
	else {
		// Display letter on screen that has been guessed:
		for (int counter = 0; counter < letterIndexesInWrd.size(); counter++) {
			QString showLine = "labelLetter" + QString::number(letterIndexesInWrd[counter]);
			Hangman::findChild<QLabel*>(showLine)->setText(valueOnButton);
		}
		// Checks to see if the user won the game:
		if (userOne.winGame() == true) {
			infoLabel->setText("You win!");
			int alphabetButtonCounter = 1;
			// Disables letters and reveal buttons:
			enableDisableButtons(false);
			revealButton->setEnabled(false);
		}
	}
	// Disables the button that the user pressed:
	Hangman::findChild<QPushButton*>(buttonName)->setEnabled(false);
	Hangman::findChild<QPushButton*>(buttonName)->setFlat(true);
}

// Resets the game for another round of Hangman:
void Hangman::on_resetButton_clicked() {

	labelLetter0->setText("");
	labelLetter1->setText("");
	labelLetter2->setText("");
	labelLetter3->setText("");
	labelLetter4->setText("");
	labelLetter5->setText("");
	infoLabel->setText("");
	beginNewGame();
	userOne.resetMemberVariables(0, 0);
}

// Reveals the word:
void Hangman::on_revealButton_clicked() {
	startMessageLabel->setText("");
	displayWord();
	enableDisableButtons(false);
	revealButton->setEnabled(false);
}

// Quits hangman game and returns user back to main form:
void Hangman::on_quitButton_clicked() {

	this->close();
	userOne.resetMemberVariables(0, 0);
}