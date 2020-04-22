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
	void setWord();
	std::string getWord();
	void guessWrongCounter();
	int getAmountGuessesWrong();
	void guessCorrectCounter();
	int getAmountGuessesCorrect();
	std::vector<int> checkWord(std::string buttonValue);
	//bool checkWord(std::string buttonValue, int &letterIndex);
	bool winGame();
	void resetMemberVariables(int wrongGuessCounter, int amountLettersPressed);
	// method to show labels and lines of how many
	// letters in the word
//	void showLabelsLinesWord();
};

#endif // HANGMAN_CUSER_H