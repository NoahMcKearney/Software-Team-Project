#include "stdafx.h"
#include "hangman.h"
#include "CUser.h"
QString qs;

Hangman::Hangman(QWidget* parent)
	: QDialog(parent)
{
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setupUi(this);
	updateUI(true);
//	QPushButton startButton;
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
	else {
		int counter = 1;
		while (counter <= 26) {
			QString buttonNames = "buttonAlphabet" + QString::number(counter);
			Hangman::findChild<QWidget*>(buttonNames)->setEnabled(false);
			counter++;
		}
		letterLines_0->setVisible(false);
		letterLines_1->setVisible(false);
		letterLines_2->setVisible(false);
		letterLines_3->setVisible(false);
		letterLines_4->setVisible(false);
		letterLines_5->setVisible(false);
		revealButton->setEnabled(false);
		resetButton->setEnabled(false);
		startButton->setVisible(true);

	}

}

void Hangman::displayWord() {
	for (int counter3 = 0; counter3 <= userOne.getWord().length()-1; counter3++) {
		QString wordLetterLabelName = "labelLetter" + QString::number(counter3);
		Hangman::findChild<QLabel*>(wordLetterLabelName)->setText(QChar::fromLatin1((userOne.getWord().at(counter3))));
	}
	endGameLabel->setText("You loss!");
}

void Hangman::beginNewGame(){
	userOne.setWord();
	int numLinesCounter = 0;
	int counter2 = 1;
	while (numLinesCounter < 34) {
//	while(counter2 <= 26){
		//QString lineNames = "line_" + QString::number(numLinesCounter);
		//Hangman::findChild<QWidget*>(lineNames)->setVisible(false);
		//numLinesCounter++;
		
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
	startButton->setVisible(false);
	beginNewGame();
	revealButton->setEnabled(true);
	resetButton->setEnabled(true);

}

void Hangman::letterPressed() {
	QPushButton* button = (QPushButton*)sender();
	QString valueOnButton = button->text();
	QString buttonName = button->objectName();

	TESTLABEL->setText(valueOnButton);
	//TESTLABEL2->setText(buttonName);
	QString word = QString::fromStdString(userOne.getWord());
	TESTLABEL3->setText(word);





	//----------EDIT BELOW, MAKE WORK IF THE USER DID NOT GUESS CORRECTLY, 
	// End of the game, did not guess correctly:


	int letterIndex = 0;
	if (userOne.getAmountGuessesWrong() != 9) {
		int counter3 = 0;
		if (userOne.winGame() == true) {
			endGameLabel->setText("You have won the game!");
		}
		else {
			if (userOne.checkWord(valueOnButton.toStdString(), letterIndex) == false) {
				// display line based upon how many guesses user gets wrong
				QString showLine = "line_" + QString::number(userOne.getAmountGuessesWrong()-1);
				Hangman::findChild<QWidget*>(showLine)->setVisible(true);
			}
			else {//if (userOne.checkWord(valueOnButton.toStdString(), letterIndex) == true) {
				// display letter
				QString showLine = "labelLetter" + QString::number(letterIndex);
				Hangman::findChild<QLabel*>(showLine)->setText(valueOnButton);
			}
		}
	}
	else {
		displayWord();
		updateUI(false);
		//endGameLabel->setText("End Game, the word is " + QString::fromStdString(userOne.getWord()));
	}
	Hangman::findChild<QPushButton*>(buttonName)->setEnabled(false);

	TESTLABEL2->setText(QString::number(userOne.getAmountGuessesWrong()));


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