#include "stdafx.h"
#include "CUser.h"
#include <vector>
#include <iostream>
#include <random>

void CUser::setWord() {

	std::string wordsArray[4] = { "cat", "bird", "earthworm", "creature" };
	
	srand(time(NULL));
	int iRandomIndex = rand() % 4 + 1;

	m_wordGuess = wordsArray[iRandomIndex];
}

std::string CUser::getWord() {
	return m_wordGuess;
}

bool CUser::checkWord(std::string buttonValue)
{
	std::string sWord = getWord();
	for (int index = 0; index < sWord.length(); index++) {
		if (sWord[index] == buttonValue[0]) {
			m_wrongGuess++;
			// Guess is wrong:
			return false;
		}
//		else if {
			
//		}
	}

}

int CUser::getAmountGuessIsWrong() {
	return m_wrongGuess;
}

/*void CUser::displayHideLetter() {
	int sizeWord = getWord().length();
	switch (sizeWord)
	{
	case 3:
		line_15->setVisible(true);
		line_16->setVisible(true);
		line_17->setVisible(true);
		break;
	}
}
*/