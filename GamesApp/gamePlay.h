#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

class GamePlay
{
private:

	std::string sSymbol;

public:
	GamePlay(std::string sStartingSymbol);
	void updateBoardProgress(int iIndex, std::string sSymbol);
	void checkBoard();
};


#endif //TIC_Tac_Toe_GAMEPLAY_H

