#include"Player.h"

void Player::operator()()
{
	std::string playerWon;

	if (won == nullptr)
	{
		playerWon = "Undefined";
	}
	else if (!(*won))
	{
		playerWon = "Lost";
	}
	else
	{
		playerWon = "Won";
	}

	std::cout << "The name is " << this->playerName << "the mode is: " << this->mode << "and the game is " << playerWon << std::endl;;
}

Player::Player(std::string* playerName, bool playerTeam)
{
	this->playerName = *playerName;
	this->playerTeam = playerTeam;
	this->playerFields = new int[5];
	this->won = nullptr;
	this->occupied_fields = 0;
}

