#pragma once
#include"Player.h"
#include"Field.h"
#include"GameLogic.h"
#include"AI.h"
#include"AILogic.h"

class PlayerInteraction{
public:
	Player** myPlayers();
	PlayerInteraction();
	void fillTheBoard(Field*** myField);
	void operator()(Field** myField, Player* playerOne, Player* playerTwo);
	void soutTheBoard(Field** myField);
	void AIInteraction(Field** myField, Player* playerOne, AI* aiOne);
private:
	int validateChoice(); // Validates the choice
};

