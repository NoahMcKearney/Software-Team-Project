#include "stdafx.h"
#include "gamePlay.h"

GamePlay::GamePlay(std::string sStartingSymbol)
{
	sSymbol = sStartingSymbol;
}
void GamePlay::updateBoardProgress(int iColumn, int iRow, std::string sSymbol)
{
	Tic_Tac_Toe_Board[iColumn][iRow] = sSymbol;
}
void GamePlay::checkBoard()
{

}