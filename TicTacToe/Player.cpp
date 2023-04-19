#include"Player.h"

void Player::operator()()
{
	std::cout << (this->playerName)<< "'s turn" << std::endl;
}

Player::Player(std::string* playerName, bool playerTeam)
{
	this->playerName = *playerName;
	this->playerTeam = playerTeam;
	this->playerFields = new int[5];
	this->won = nullptr;
	this->occupied_fields = 0;
}

Player::Player()
{
	this->playerFields = new int[5];
	this->won = nullptr;
	this->occupied_fields = 0;
}

