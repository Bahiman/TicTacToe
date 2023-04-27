#pragma once
class Field
{
public:
	Field(int coordinate);
	int coordinate;
	bool* occupied; // null
	char chr; // - x o
	void operator()(bool team);
};
