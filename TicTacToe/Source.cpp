#include"PlayerInteraction.h"
#include"Field.h"

int main()
{
	PlayerInteraction p;

	Player** players = p.myPlayers();

	Player* playerOne = players[0];

	Player* playerTwo = players[1];

	(*playerOne)();
	(*playerTwo)();

	std::cout << "Note that the coordinates look like this:" << std::endl;

	std::cout << "---" << "\n---" << "\n---" << std::endl;

	std::cout << "and the coordinate numbers will look like this" << "\n012" << "\n345" << "\n678" << std::endl;
	
	Field** board = new Field*[9];

	p.fillTheBoard(&board);
	
	p(board,playerOne,playerTwo);
}