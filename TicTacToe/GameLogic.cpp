#include "GameLogic.h"

GameLogic::GameLogic()
{
}

void GameLogic::checkForWin(Player* myPlayer)
{
	int counter = 0;

	auto* myFieldsVector = new std::vector<int>{};

	myFieldsVector->assign(myPlayer->playerFields, myPlayer->playerFields + myPlayer->occupied_fields);
	std::sort(myFieldsVector->begin(), myFieldsVector->end());

	std::string* myFieldString = new std::string();

	for (auto k : *myFieldsVector)
	{
		*myFieldString += std::to_string(k);
	}

	delete myFieldsVector;

	if (myFieldString->size() < 3)
	{
		myPlayer->won = new bool(false);
		return;
		delete myFieldString;
	}
	else if (myFieldString->size() == 3)
	{
		for (int i = 0; i < 8; i++)
		{
			if ((*myFieldString) == *(winningCombinations[i]))
			{
				myPlayer->won = new bool(true);
				return;
			}
		}

		delete myFieldString;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			auto it = std::search(myFieldString->begin(), myFieldString->end(), winningCombinations[i]->begin(), winningCombinations[i]->end());
			
			if (it != myFieldString->end())
			{
				myPlayer->won = new bool(true);
				return;
			}
		}
		
		delete myFieldString;
	}


}

int GameLogic::occupy(Field** myFields, int indexToMark, Player* thePLayer)
{	
	bool check = checkForOccupied(myFields, indexToMark);

	if (!check)
	{
		myFields[indexToMark]->occupied = new bool(thePLayer->playerTeam);

		(*myFields[indexToMark])(thePLayer->playerTeam);

		thePLayer->playerFields[thePLayer->occupied_fields] = indexToMark;

		thePLayer->occupied_fields++;

		return 0;
	}
	else
	{
		return 333;
	}
}

bool GameLogic::checkForOccupied(Field** myField, int indexToCheck)
{
	if (myField[indexToCheck]->occupied == nullptr)
	{
		return false;
	} 
	else
	{

		return true;
	}
}
