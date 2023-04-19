#pragma once
#include"GameLogic.h"
#include"AI.h"
class AILogic : public GameLogic{
public:
	int findTheBestMoveForAI(AI* ai, Player* player, Field** field);
private:
	int findTheBestMoveForAi_(AI*, Player* player, Field** field);
	int findTheBestMoveForPLayer(Player* player, Field** field);
	int findTheBestMoveForPLayer_(Player* player, Field** field);
};