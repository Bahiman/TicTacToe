#pragma once
#include"Player.h"
#include"Field.h"
#include"GameLogic.h"

class PlayerInteraction{
public:
	Player** myPlayers();
	PlayerInteraction();
	void fillTheBoard(Field*** myField);
	void operator()(Field** myField, Player* playerOne, Player* playerTwo);
	void soutTheBoard(Field** myField);
private:
	int validateChoice(); // Validates the choice
};

