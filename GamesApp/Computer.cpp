#include "stdafx.h"
#include "Computer.h"
#include <random>
#include "tic_tac_toe_game.h"
#include "ui_Tic_Tac_Toe.h"

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
std::string Computer::getFontColor()
{
	if (sSymbol == "O")
	{
		return "color: Red; background-color: White";
	}
	else
	{
		return "color: Blue; background-color: White";
	}
}