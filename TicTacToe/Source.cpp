#include"PlayerInteraction.h"
#include"Field.h"

int main()
{
	PlayerInteraction* p = new PlayerInteraction;

	Player** players = (*p).myPlayers();

	Player* playerOne = *players;

	Player* playerTwo = nullptr;

	bool dualPlayer = playerOne->mode == false;

	if (dualPlayer)
	{
		playerTwo = players[1];
	}

	(*playerOne)();

	std::cout << "Note that the coordinates look like this:" << std::endl;

	std::cout << "---" << "\n---" << "\n---" << std::endl;

	std::cout << "and the coordinate numbers will look like this" << "\n012" << "\n345" << "\n678" << std::endl;
	
	Field** board = new Field*[9];

	AI* ai = new AI();

	p->fillTheBoard(&board);
	
	if (dualPlayer)
	{
		(*p)(board,playerOne,playerTwo);
	} 
	else
	{
		p->AIInteraction(board, playerOne, ai);

		// 
	}

}