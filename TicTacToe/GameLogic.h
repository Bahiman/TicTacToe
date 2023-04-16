#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include"Field.h"
#include "Player.h"
class GameLogic
{
public:
	GameLogic();
	
	void checkForWin(Player* myPlayer);

	bool checkForOccupied(Field** myField, int indexToCheck);

	int occupy(Field** myFields, int indexToMark, Player* thePLayer);

private:
	std::string** winningCombinations = new std::string* [8]
	{	new std::string("048"),
		new std::string("036"),
		new std::string("147"),
		new std::string("246"),
		new std::string("345"),
		new std::string("258"),
		new std::string("678"),
		new std::string("012")
	};

};
