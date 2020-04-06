#include "stdafx.h"
#include "hangman.h"

Hangman::Hangman(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	QPushButton *alphabetButtons[26];
	for(int counter = 0; counter < 26; ++counter){
		QString buttonName = "buttonAlphabet" + QString::number(counter+1);
		alphabetButtons[counter] = Hangman::findChild<QPushButton *>(buttonName);
		// when released
		connect(alphabetButtons[counter], SIGNAL(released()), this, SLOT(letterPressed()));
	}

}

// destructor    
Hangman::~Hangman()
{
}

void Hangman::letterPressed() {
//	QPushButton* button = (QPushButton*)sender();
//	QString buttonValue = button->text();

	

}