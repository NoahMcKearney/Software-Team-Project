#include "stdafx.h"
#include "Computer.h"
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


