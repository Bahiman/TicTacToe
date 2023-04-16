#include "Field.h"

Field::Field(int coordinate)
{
	this->coordinate = coordinate;
	chr = '-';
	occupied = nullptr;
}

void Field::operator()(bool team)
{
	if (team == true)
	{
		this->chr = 'X';
	} 
	else
	{
		this->chr = 'O';
	}
}