#include "stdafx.h"
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include<fstream>
#include "CUser.h"

void CUser::setWord() {

	std::string line;
	std::vector<std::string> lines;
	srand(time(0));
	// Opens a file and reads it:
	std::ifstream file("hangman_words.txt");

	int total_lines = 0;
	while (std::getline(file, line)) {
		total_lines++;
		lines.push_back(line);
	}

	int random_number = rand() % total_lines;
	// updates the m_wordGuess member variable with a random word:
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

void CUser::guessCorrectCounter() {
	m_correctGuess++;
}

int CUser::getAmountGuessesCorrect() {
	return m_correctGuess;
}

// This function checks to see if the letter pressed by the user is in the word:
std::vector<int> CUser::checkWord(std::string buttonValue) {

	std::string sWord = getWord();
	std::vector<int> lettersInWordVector;
	// Empties vector:
	lettersInWordVector.clear();
	for (int index = 0; index <= sWord.length(); index++) {
		if (sWord[index] == buttonValue[0]) {
			// if letter is found in word, add the index to vector:
			lettersInWordVector.push_back(index);
			guessCorrectCounter();
		}
		else if (index == sWord.length()) {
			// Reached end of the word:
			return lettersInWordVector;
		}
		else {
			continue;
		}
	}

}

bool CUser::winGame() {
	
	// Checks to see if the user guesses the word correctly:
	if (getAmountGuessesCorrect() == getWord().length()) {
		return true;
	}
	else {
		return false;
	}
}

// Resets the game by setting member variables back to zero:
void CUser::resetMemberVariables(int wrongGuessCounter, int amountLettersPressed) {

	m_wrongGuess = wrongGuessCounter;
	m_amountLettersPressed = amountLettersPressed;
	m_correctGuess = 0;
}