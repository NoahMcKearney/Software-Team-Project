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
void Player::updateBoard(int iButtonNum)
{
	//BoardVector[iButtonNum] = sSymbol;
	//ui."nameOfButton"->setEnabled(false);
}


