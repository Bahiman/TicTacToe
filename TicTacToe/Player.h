#pragma once
#include<iostream>
class Player{
public:
	std::string playerName; // The username of the player
	bool playerTeam; // If the player is x or o true means x and false means o
	int* playerFields; // The fields occupied by the player
	bool* won;
	virtual void operator()(); // Will print out all of the information about the player
	int occupied_fields; // Shows how many fields are occupied by the player
	Player(std::string* playerName, bool playerTeam); // set the constructor
	Player();
	bool mode; // false means pvp and true means vs AI
};