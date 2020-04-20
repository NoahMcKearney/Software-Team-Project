#include "stdafx.h"
#include "Player.h"
#include <vector>
//#include "tic_tac_toe.h"

Player::Player(std::string sStartingSymbol)
{
	 sSymbol = sStartingSymbol;
}
void Player::setSymbol(std::string sUpdateSymbol)
{
	sSymbol = sUpdateSymbol;
}
std::string Player::getSymbol()
{
	return sSymbol;
}
std::string Player::getFontColor()
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


