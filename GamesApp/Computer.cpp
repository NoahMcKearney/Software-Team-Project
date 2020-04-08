#include "stdafx.h"
#include "Computer.h"
#include "gamePlay.h"
#include <random>

Computer::Computer(std::string sStartingSymbol)
{
	sSymbol = sStartingSymbol;
}
void Computer::setSymbol(std::string sUpdateSymbol)
{
	sSymbol = sUpdateSymbol;
}
std::string Computer::getSymbol()
{
	return sSymbol;
}
void Computer::computerTurn()
{
	int iRand = rand() % 10;
	board.updateBoardProgress(0, 2, "e");
}
