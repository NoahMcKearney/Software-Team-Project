#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
class GamePlay
{
private:
	std::string Tic_Tac_Toe_Board[3][3];
	std::string sSymbol;

public:
	GamePlay(std::string sStartingSymbol);
	void updateBoardProgress(int iColumn, int iRow, std::string sSymbol);
	void checkBoard();
};


#endif //TIC_Tac_Toe_GAMEPLAY_H

