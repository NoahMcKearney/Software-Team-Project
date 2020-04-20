#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
class Computer
{
private:
	int iRandNum;
	std::string sSymbol;

public:
	Computer(std::string sStartingSymbol);
	void setSymbol(std::string sUpdateSymbol);
	std::string getSymbol();
	std::string getFontColor();
};

#endif //TIC_Tac_Toe_COMPUTER_H
