#pragma once
#ifndef HANGMAN_CUSER_H
#define HANGMAN_CUSER_H
class CUser
{
private:
	std::string m_wordGuess;
	int m_wrongGuess = 0;
	int m_amountLettersPressed{ 0 };
	int m_correctGuess = 0;
public:
	// Finds a word from a file randomly:
	void setWord();
	// Returns the random word that the user is trying to guess:
	std::string getWord();
	void guessWrongCounter();
	int getAmountGuessesWrong();
	void guessCorrectCounter();
	int getAmountGuessesCorrect();
	std::vector<int> checkWord(std::string buttonValue);
	// Decides if the user won the game or not:
	bool winGame();
	void resetMemberVariables(int wrongGuessCounter, int amountLettersPressed);
};

#endif // HANGMAN_CUSER_H