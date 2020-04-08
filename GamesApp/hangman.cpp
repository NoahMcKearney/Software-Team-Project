#include "stdafx.h"
#include "hangman.h"
#include "CUser.h"
QString qs;

Hangman::Hangman(QWidget* parent)
	: QDialog(parent)
{
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

void Hangman::on_startButton_clicked() {

	userOne.setWord();
	startButton->setVisible(false);
	for (int counter2 = 0; counter2 <= 19; ++counter2) {
		QString lineNames = "line_" + QString::number(counter2);
		Hangman::findChild<QWidget*>(lineNames)->setVisible(false);
	}
}

void Hangman::letterPressed() {
	QPushButton* button = (QPushButton*)sender();
	QString valueOnButton = button->text();
	QString buttonName = button->objectName();

	if (userOne.checkWord(valueOnButton.toStdString()) == false) {
		// display line based upon how many guesses got wrong
		
	}
	else {
		// display letter
	}
	Hangman::findChild<QPushButton*>(buttonName)->setEnabled(false);

}
