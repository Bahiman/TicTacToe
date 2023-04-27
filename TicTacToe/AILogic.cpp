#include "AILogic.h"
#include <unordered_set>


/// <summary>
///		01 | 2 ||| 4 
/// </summary>
/// <param name="ai"></param>
/// <param name="player"></param>
/// <param name="field"></param>
/// <returns></returns>

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
				std::string* myStringCopy = new std::string (*winningCombinations[f]);
				myStringCopy->erase(index, myFieldString->length());
				myLeftVector->push_back((*myStringCopy)[0]);
 			}
		}
		
		auto* unOccupiedFields = new std::vector<char>();

		for (auto i = 0; i < 9; i++)
		{
			auto field_ = (field)[i];

			if (field_->occupied == nullptr)
			{
				unOccupiedFields->push_back(static_cast<char>(field_->coordinate + '0'));
			}
		}

		for(auto k : *myLeftVector)
		{
			for (auto kk : *unOccupiedFields)
			{
				if (k == kk)
				{
					int r = static_cast<int>(kk - '0');

					return r; 
				}
			}
		}

		delete myLeftVector;

		delete unOccupiedFields;
 
		return findTheBestMoveForPLayer(player, field);
	}
	else if (ai->occupied_fields == 3)
	{
		auto* stringSet = new std::set<std::string*>{};

		auto* myIntVector = new std::vector<int>{};// get the fields of the ai into a vector

		myIntVector->assign(ai->playerFields, ai->playerFields + ai->occupied_fields);

		std::sort(myIntVector->begin(), myIntVector->end());

		for (int i = 0; i < myIntVector->size(); i++)
		{
			for (int j = 0; j < myIntVector->size(); j++)
			{
				if (i != j)
				{

					std::string f = "";

					f += static_cast<char>(i + '0');

					f += static_cast<char>(j + '0'); 

					stringSet->insert(&f);
				}
			}
		}

		delete myIntVector;
		
		for (auto myFieldString : *stringSet)
		{
			auto* myLeftVector = new std::vector<char>();

			for (auto f = 0; f < 8; f++)
			{
				size_t index = winningCombinations[f]->find(*myFieldString);

				if (index != std::string::npos)
				{
					std::string** myStringCopy = new std::string * (winningCombinations[f]);
					(*myStringCopy)->erase(index, myFieldString->length());
					myLeftVector->push_back((*(*myStringCopy))[0]);
					delete myStringCopy;
				}
			}

			auto* unOccupiedFields = new std::vector<char>();

			for (auto i = 0; i < 9; i++)
			{
				auto field_ = (field)[i];

				if (field_->occupied == nullptr)
				{
					unOccupiedFields->push_back(static_cast<char>(field_->coordinate + '0'));
				}
			}

			for (auto k : *myLeftVector)
			{
				for (auto kk : *unOccupiedFields)
				{
					if (k == kk)
					{
						int r = static_cast<int>(kk - '0');

						return r;
					}
				}
			}

			delete myLeftVector;

			delete unOccupiedFields;
		}


		findTheBestMoveForPLayer_(player, field);
	} 
	else 
	{
		return 999;
	}
	
}

int AILogic::findTheBestMoveForPLayer(Player* player, Field** field)

{
	(*player)();
	std::cout << 2 << std::endl;


	auto* myIntVector = new std::vector<int>{};// get the fields of the player into a vector

	myIntVector->assign(player->playerFields, player->playerFields + player->occupied_fields);

	std::sort(myIntVector->begin(), myIntVector->end());

	std::string* myFieldString = new std::string();

	for (auto l : *myIntVector)
	{
		*myFieldString += std::to_string(l);
	}


	auto* myLeftVector = new std::vector<char>();

	for (auto f = 0; f < 8; f++)
	{

		auto m = [](std::string* num, std::string* target) {

			int myNigga[2] = {};

			int counter = 0;

			for (int i = 0; i < (*target).size() ; i++)
			{
				for (int j = 0; j < num->size(); j++)
				{

					if ((*num)[j] == (*target)[i])
					{
						counter++;
						if (counter == 1)
						{
							myNigga[0] = i;
						}
						else if (counter == 2)
						{
							myNigga[1] = i;

						}
					}
				}
			}

			if (counter == 2)
			{
				target->erase(myNigga[0], 1);
				target->erase(static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(myNigga[1]) - 1, 1);

				return true;
			}
			else
			{
				return false;
			}
		};
		
		size_t index = (*winningCombinations[f]).find(*myFieldString);

		std::string* myCopy = new std::string((*winningCombinations[f]));

		if (m(myFieldString, myCopy))
		{
			myLeftVector->push_back((*myCopy)[0]);
			delete myCopy;
		}
	}

	auto* unOccupiedFields = new std::vector<char>();

	for (auto i = 0; i < 9; i++)	
	{
		auto field_ = (field)[i];

		if (field_->occupied == nullptr)
		{
			unOccupiedFields->push_back(static_cast<char>(field_->coordinate + '0'));
		}
	}



	for (auto k : *myLeftVector)
	{
		for (auto kk : *unOccupiedFields)
		{
			if (k == kk)
			{
				int r = static_cast<int>(kk - '0');


				return r;
			}
		}
	}

	delete myFieldString;

	delete myLeftVector;

	auto contains = [unOccupiedFields](int r)
	{
		if (std::find(unOccupiedFields->begin(), unOccupiedFields->end(), r) != unOccupiedFields->end())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	for (auto k : *myIntVector)
	{
		if (k == 0 || k == 2 || k == 6 || k == 8)
		{
			switch (k)
			{
			
			case 0:
				if (contains(0))
				{
					return 6;
				}
				break;

			case 2 :
				if (contains(2))
				{
					return 8;
				}
				break;

			case 6:
				if (contains(6))
				{
					return 0;
				}
				break;

			case 8:

				if (contains(8))
				{
					return 2;
				}

				break;

			default:
				break;
			}
		}
	}

	return static_cast<int>((*unOccupiedFields)[0] + '0');
}

int AILogic::findTheBestMoveForPLayer_(Player* ai, Field** field)
{
	auto unOccupied = new std::vector<char>();

	auto* stringSet = new std::set<std::string*>{};

	auto* myIntVector = new std::vector<int>{};// get the fields of the ai into a vector

	myIntVector->assign(ai->playerFields, ai->playerFields + ai->occupied_fields);

	std::sort(myIntVector->begin(), myIntVector->end());

	for (int i = 0; i < myIntVector->size(); i++)
	{
		for (int j = 0; j < myIntVector->size(); j++)
		{
			if (i != j)
			{

				std::string f = "";

				f += static_cast<char>(i + '0');

				f += static_cast<char>(j + '0');

				stringSet->insert(&f);
			}
		}
	}

	delete myIntVector;

	for (auto myFieldString : *stringSet)
	{
		auto* myLeftVector = new std::vector<char>();

		for (auto f = 0; f < 8; f++)
		{

			auto m = [](std::string* num, std::string* target) {

				int myNigga[2] = {};

				int counter = 0;

				for (int i = 0; i < (*target).size(); i++)
				{
					for (int j = 0; j < num->size(); j++)
					{

						if ((*num)[j] == (*target)[i])
						{
							counter++;
							if (counter == 1)
							{
								myNigga[0] = i;
							}
							else if (counter == 2)
							{
								myNigga[1] = i;

							}
						}
					}
				}

				if (counter == 2)
				{
					target->erase(myNigga[0], 1);
					target->erase(static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(myNigga[1]) - 1, 1);

					return true;
				}
				else
				{
					return false;
				}
			};

			size_t index = (*winningCombinations[f]).find(*myFieldString);

			std::string* myCopy = new std::string((*winningCombinations[f]));

			if (m(myFieldString, myCopy))
			{
				myLeftVector->push_back((*myCopy)[0]);
				delete myCopy;
			}
		}

		std::cout << myLeftVector->size() << 123123 << std::endl;


		auto* unOccupiedFields = new std::vector<char>();

		unOccupied = unOccupiedFields;

		for (auto i = 0; i < 9; i++)
		{
			auto field_ = (field)[i];

			if (field_->occupied == nullptr)
			{
				unOccupiedFields->push_back(static_cast<char>(field_->coordinate + '0'));
			}
		}



		for (auto k : *myLeftVector)
		{
			for (auto kk : *unOccupiedFields)
			{
				if (k == kk)
				{
					int r = static_cast<int>(kk - '0');


					return r;
				}
			}
		}

		delete myFieldString;

		delete myLeftVector;

		return static_cast<int>((*unOccupiedFields)[0] + '0');
	}

	return static_cast<int>((*unOccupied)[0] + '0');

}

