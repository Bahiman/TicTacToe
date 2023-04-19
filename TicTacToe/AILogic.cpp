#include "AILogic.h"

int AILogic::findTheBestMoveForAI(AI* ai, Player* player, Field** field)
{
	if (!ai->occupied_fields) 
	{
		return 4;
		ai->occupied_fields++;
	}
	else if (ai->occupied_fields == 1)
	{
		
		auto checkIfOneOfTheCornersIsOccupied = [ai, player, field] 
		{
			std::vector<int>* myNumbers = new std::vector<int>(player->playerFields, player->playerFields + player->occupied_fields);
			for (int i = 0; i < 4; i++)
			{
				int checkNumber = 0;

				if(std::find(myNumbers->begin(), myNumbers->end(), checkNumber) != myNumbers->end())
				{
					return checkNumber;
				}

				if(checkNumber == 0)
				{
					checkNumber = 2;
					continue;
				}
				else if (checkNumber == 2)
				{
					checkNumber = 6;
				}
				else if (checkNumber == 6)
				{
					checkNumber = 8;
				}
			}

			return 0;
		};

		auto m = checkIfOneOfTheCornersIsOccupied();

		if (m)
		{
			if (m == 0)
			{
				return 6;
			}
			else if (m == 2)
			{
				return 8;
			}
			else if (m == 6)
			{
				return 0;
			}
			else if(m == 8)
			{
				return 2;
			}
		} 
		else
		{
			return 0;
		}

		ai->occupied_fields++;
	}
	else if(ai->occupied_fields == 2)
	{
		auto* myIntVector = new std::vector<int>{};// get the fields of the ai into a vector
		 
		myIntVector->assign(ai->playerFields , ai->playerFields + ai->occupied_fields); 

		std::sort(myIntVector->begin(), myIntVector->end());

		std::string* myFieldString = new std::string();

		for (auto l : *myIntVector)
		{
			*myFieldString += std::to_string(l);
		}

		delete myIntVector;

		auto* myLeftVector = new std::vector<char>();
		
		for (auto f = 0; f < 8; f++)
		{
			size_t index = winningCombinations[f]->find(*myFieldString);

			if (index != std::string::npos)
			{
				auto* myStringCopy = winningCombinations[f];
				myStringCopy->erase(index, myFieldString->length());
				myLeftVector->push_back((*myStringCopy)[0]);
				//delete myStringCopy;
 			}
		}
		
		auto* unOccupiedFields = new std::vector<char>();

		for (auto i = 0; i < 9; i++)
		{
			auto field_ = (field)[i];

			if (field_->occupied == nullptr)
			{
				std::cout << static_cast<char>(field_->coordinate + '0') << " is the c" << field_->coordinate << std::endl;
				unOccupiedFields->push_back(static_cast<char>(field_->coordinate + '0'));
			}
		}

		for(auto k : *myLeftVector)
		{
			for (auto kk : *unOccupiedFields)
			{
				if (k == kk)
				{
					int r = kk - '0';

					std::cout << r << "???" << k;

					return r; 
				}
				else
				{
					std::cout << kk << "!!!" << std::endl;
				}
			}
		}

		delete myLeftVector;

		delete unOccupiedFields;
	}



}

int AILogic::findTheBestMoveForPLayer(Player* player, Field** field)
{
	auto* myIntVector = new std::vector<int>{};// get the fields of the player into a vector

	myIntVector->assign(player->playerFields, player->playerFields + player->occupied_fields);

	std::sort(myIntVector->begin(), myIntVector->end());

	std::string* myFieldString = new std::string();

	for (auto l : *myIntVector)
	{
		*myFieldString += std::to_string(l);
	}

	delete myIntVector;

	auto* myLeftVector = new std::vector<char>();

	for (auto f = 0; f < 8; f++)
	{
		size_t index = winningCombinations[f]->find(*myFieldString);

		if (index != std::string::npos)
		{
			auto* myStringCopy = winningCombinations[f];
			myStringCopy->erase(index, myFieldString->length());
			myLeftVector->push_back((*myStringCopy)[0]);
			delete myStringCopy;
		}
	}

	auto* unOccupiedFields = new std::vector<char>();

	for (auto i = 0; i < 9; i++)
	{
		auto field_ = (field)[i];

		if (field_->occupied == nullptr)
		{
			unOccupiedFields->push_back(static_cast<char>(field_->coordinate - '0'));
		}
	}

	for (auto k : *myLeftVector)
	{
		for (auto kk : *unOccupiedFields)
		{
			if (k == kk)
			{
				int r = kk - '0';

				delete myLeftVector;

				delete unOccupiedFields;

				return r;
			}
		}
	}

	delete myFieldString;
	delete myLeftVector;

	return (*unOccupiedFields)[0];
}

int AILogic::findTheBestMoveForAi_(AI*, Player* player, Field** field)
{
	return 0;
}




int AILogic::findTheBestMoveForPLayer_(Player* player, Field** field)
{
	return 0;
}

