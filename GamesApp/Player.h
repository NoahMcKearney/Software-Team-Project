#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	std::string sSymbol;

public:
	Player(std::string sStartingImage);
	void setSymbol(std::string sUpdateSymbol);
	std::string getSymbol();
	std::string getFontColor();
};

#endif //TIC_Tac_Toe_PLAYER_H
