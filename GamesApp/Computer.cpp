#include "stdafx.h"
#include "Computer.h"
#include "gamePlay.h"
//#include "tic_tac_toe.h"
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
	/*bool bSpotTaken = false;
	while (!bSpotTaken)
	{
		int index = rand() % 8 + 0;

		if (sSymbol == BoardVector[index])
		{
			bSpotTaken = true;
		}
		else
		{
			BoardVector[index] = sSymbol;
			//ui."nameOfButton"->setEnabled(false);
		}
	}*/
}


