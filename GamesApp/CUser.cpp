#include "stdafx.h"
#include "CUser.h"
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include<fstream>
#include<tuple>
//#include<fstream>

void CUser::setWord() {
	
	// open a file and read:
	std::string line;
	// vector of words from file to choose from:
	std::vector<std::string> lines;

	srand(time(0));
	std::ifstream file("hangman_words.txt");

	int total_lines = 0;
	while (std::getline(file, line)) {
		total_lines++;
		lines.push_back(line);
	}

	int random_number = rand() % total_lines;
	m_wordGuess = lines[random_number];
}

std::string CUser::getWord() {
	return m_wordGuess;
}

void CUser::guessWrongCounter() {
	m_wrongGuess++;
}

int CUser::getAmountGuessesWrong() {
	return m_wrongGuess;
}

bool CUser::checkWord(std::string buttonValue, int &letterIndex)
{
	std::string sWord = getWord();
	for (int index = 0; index < sWord.length(); index++) {
		
		if (sWord[index] == buttonValue[0]) {
			letterIndex = index;
			m_lettersGuessedCorrectly++;
			// Guess is correct:
			return true;
		}
		else if (index+1 == sWord.length()) {
			guessWrongCounter();
			// Guess is wrong:
			return false;
		}
		else {
			continue;
		}
	}

}

bool CUser::winGame() {
	
	if (m_lettersGuessedCorrectly == (getWord().length())) {
		return true;
	}
	else {
		return false;
	}

}

void CUser::resetMemberVariables(int wrongGuessCounter, int amountLettersPressed) {
	m_wrongGuess = wrongGuessCounter;
	m_amountLettersPressed = amountLettersPressed;
	m_lettersGuessedCorrectly = 0;
}


// -----CONSIDER DELETING AT THE END----
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