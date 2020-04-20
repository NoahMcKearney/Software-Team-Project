#include "stdafx.h"
#include "hangman.h"
#include "CUser.h"
QString qs;

Hangman::Hangman(QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setupUi(this);
	QPushButton startButton;
	QPushButton* alphabetButtons[26];
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

void Hangman::updateUI(bool bGuessingWord) {
	int lengthWord = userOne.getWord().length();

	if (bGuessingWord == false) {
		// -------MIGHT WANT TO PUT BELOW INTO A FUNCTION IN HANGMAN.CPP FOR LATER WHEN RESET GAME.....-------
		switch (lengthWord) {
		case 3:
			letterLines_0->setVisible(true);
			letterLines_1->setVisible(true);
			letterLines_2->setVisible(true);
			break;
		case 4:
			letterLines_0->setVisible(true);
			letterLines_1->setVisible(true);
			letterLines_2->setVisible(true);
			letterLines_3->setVisible(true);
			break;
		case 5:
			letterLines_0->setVisible(true);
			letterLines_1->setVisible(true);
			letterLines_2->setVisible(true);
			letterLines_3->setVisible(true);
			letterLines_4->setVisible(true);
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
	else {

	}
}

void Hangman::beginNewGame(){
	userOne.setWord();
	startButton->setVisible(false);
	int numLinesCounter = 0;
	int counter2 = 1;
	while (numLinesCounter < 34) {
		//QString lineNames = "line_" + QString::number(numLinesCounter);
		//Hangman::findChild<QWidget*>(lineNames)->setVisible(false);
		//numLinesCounter++;
		//----------

		if (numLinesCounter < 9) {
			QString lineNames = "line_" + QString::number(numLinesCounter);
			Hangman::findChild<QWidget*>(lineNames)->setVisible(false);
		}
		else {
			QString buttonNames = "buttonAlphabet" + QString::number(counter2);
			Hangman::findChild<QWidget*>(buttonNames)->setEnabled(true);
			counter2++;
		}
		numLinesCounter++;
		
	}
	updateUI(false);
}

void Hangman::on_startButton_clicked() {

	beginNewGame();
}

void Hangman::letterPressed() {
	QPushButton* button = (QPushButton*)sender();
	QString valueOnButton = button->text();
	QString buttonName = button->objectName();

	TESTLABEL->setText(valueOnButton);
	TESTLABEL2->setText(buttonName);
	QString word = QString::fromStdString(userOne.getWord());
	TESTLABEL3->setText(word);

	//----------EDIT BELOW, MAKE WORK IF THE USER DID NOT GUESS CORRECTLY, 
	// End of the game, did not guess correctly:


	if (userOne.getAmountGuessesWrong() == 14) {
		endGameLabel->setText("End Game, the word is " + QString::fromStdString(userOne.getWord()));
	}

	int letterIndex = 0;
	if (userOne.checkWord(valueOnButton.toStdString(), letterIndex) == false) {
		// display line based upon how many guesses user gets wrong
		QString showLine = "line_" + QString::number(userOne.getAmountGuessesWrong());
		Hangman::findChild<QWidget*>(showLine)->setVisible(true);
	}
	else if(userOne.checkWord(valueOnButton.toStdString(), letterIndex) == true) {
		// display letter
		QString showLine = "labelLetter" + QString::number(letterIndex);
		Hangman::findChild<QLabel*>(showLine)->setText(valueOnButton);
	}
	
	// Check to see if the user wond the game or not...
//	if()

	Hangman::findChild<QPushButton*>(buttonName)->setEnabled(false);

}

void Hangman::on_quitButton_clicked() {
	this->close();
}

void Hangman::on_resetButton_clicked() {
	labelLetter0->setText("");
	labelLetter1->setText("");
	labelLetter2->setText("");
	labelLetter3->setText("");
	labelLetter4->setText("");
	labelLetter5->setText("");
	beginNewGame();
	userOne.resetMemberVariables(0, 0);


}