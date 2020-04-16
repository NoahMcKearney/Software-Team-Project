#include "stdafx.h"
#include "gamePlay.h"
#include <vector>

GamePlay::GamePlay(std::string sStartingSymbol)
{

	sSymbol = sStartingSymbol;
}
void GamePlay::updateBoardProgress(int iIndex, std::string sSymbol)
{

//	BoardArray(iIndex) = sSymbol;

}
void GamePlay::checkBoard()
{
	const int size = 8;
	std::vector<std::string> BoardVector(size);
	for (int counter = 0; counter < BoardVector.size(); counter++)
	{

	}
}