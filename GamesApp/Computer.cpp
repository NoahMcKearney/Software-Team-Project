#include "stdafx.h"
#include "Computer.h"

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
