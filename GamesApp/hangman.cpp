#include "stdafx.h"
#include "hangman.h"
#include "CUser.h"
QString qs;

Hangman::Hangman(QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setupUi(this);
	beginNewGame();
//	QPushButton startButton;
	QPushButton* alphabetButtons[26];
	// Allows the alphabet buttons to be clickable:
	for (int counter = 0; counter < 26; ++counter) {
		QString buttonName = "buttonAlphabet" + QString::number(counter + 1);
		alphabetButtons[counter] = Hangman::findChild<QPushButton*>(buttonName);
		// when released
		connect(alphabetButtons[counter], SIGNAL(released()), this, SLOT(letterPressed()));
	}
}

CUser userOne;

// destructor    
Hangman::~Hangman()
{
}

void Hangman::enableDisableButtons(bool enableButtons) {
	int buttonCounter = 1;
	
	if (enableButtons == true) {
		while (buttonCounter <= 26) {
			QString buttonNames = "buttonAlphabet" + QString::number(buttonCounter);
			Hangman::findChild<QWidget*>(buttonNames)->setEnabled(true);
			buttonCounter++;
		}
	}
	else {
		while (buttonCounter <= 26) {
			QString buttonNames = "buttonAlphabet" + QString::number(buttonCounter);
			Hangman::findChild<QWidget*>(buttonNames)->setEnabled(false);
			buttonCounter++;
		}
	}
}

void Hangman::beginNewGame() {
	startMessageLabel->setText("Welcome to the Hangman, press any letter to begin!");
	userOne.setWord();
	int numLinesButtonsCounter = 0;
	int buttonAphabetCounter = 1;
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
	revealButton->setEnabled(true);
	resetButton->setEnabled(true);
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

void Hangman::displayWord() {
	for (int counter3 = 0; counter3 <= userOne.getWord().length()-1; counter3++) {
		QString wordLetterLabelName = "labelLetter" + QString::number(counter3);
		Hangman::findChild<QLabel*>(wordLetterLabelName)->setText(QChar::fromLatin1((userOne.getWord().at(counter3))));
	}
}

void Hangman::letterPressed() {	
	QPushButton* button = (QPushButton*)sender();
	QString buttonName = button->objectName();

//	TESTLABEL->setText(valueOnButton);
	//TESTLABEL2->setText(buttonName);

	//--------------Keep Below:

	QString valueOnButton = button->text();
	QString word = QString::fromStdString(userOne.getWord());
	TESTLABEL3->setText("word:"+word);
	startMessageLabel->setText("");
	int letterIndex = 0;
	if (userOne.getAmountGuessesWrong() != 9) {
		int counter3 = 0;
		if (userOne.winGame() == true) {
			infoLabel->setText("You Win!");
			int alphabetButtonCounter = 1;
			// Disables alphabet buttons:
			enableDisableButtons(false);
			revealButton->setEnabled(false);
		}
		else {
			// Creates a vector and copies from created vector in checkWord() method:
			std::vector<int>letterIndexesInWrd = userOne.checkWord(valueOnButton.toStdString());

			TESTLABEL4->setText("size Vector: " + QString::number(letterIndexesInWrd.size()));

			if (letterIndexesInWrd.size() == 0) {
				// display line based upon how many guesses user gets wrong
				userOne.guessWrongCounter();
				QString showLine = "line_" + QString::number(userOne.getAmountGuessesWrong()-1);
				Hangman::findChild<QWidget*>(showLine)->setVisible(true);
			}
			else {//if (userOne.checkWord(valueOnButton.toStdString(), letterIndex) == true) {
				// Display letter on screen that has been guessed:
				for (int counter = 0; counter < letterIndexesInWrd.size(); counter++) {
					QString showLine = "labelLetter" + QString::number(letterIndexesInWrd[counter]);
					Hangman::findChild<QLabel*>(showLine)->setText(valueOnButton);
				}
				
			}
		}
	}
	else {
		displayWord();
		enableDisableButtons(false);
//		updateUI(false);
		//endGameLabel->setText("End Game, the word is " + QString::fromStdString(userOne.getWord()));
	}
	Hangman::findChild<QPushButton*>(buttonName)->setEnabled(false);

	TESTLABEL2->setText("correct:"+QString::number(userOne.getAmountGuessesCorrect()));
}

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

void Hangman::on_revealButton_clicked() {
	displayWord();
	enableDisableButtons(false);
	revealButton->setEnabled(false);
}

void Hangman::on_quitButton_clicked() {
	this->close();
}