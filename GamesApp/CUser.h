#pragma once
#ifndef HANGMAN_CUSER_H
#define HANGMAN_CUSER_H
class CUser
{
private:
	std::string m_wordGuess;
	int m_wrongGuess = 0;
	int m_amountLettersPressed{ 0 };
public:
	void setWord();
	std::string getWord();
	bool checkWord(std::string buttonValue);
	int getAmountGuessIsWrong();
	// method to show labels and lines of how many
	// letters in the word
//	void showLabelsLinesWord();
};

#endif // HANGMAN_CUSER_H