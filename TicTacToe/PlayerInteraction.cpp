#include "PlayerInteraction.h"

int PlayerInteraction::validateChoice()
{
    std::cout << "Enter the mode(1 - Player vs Player; 2 - Player vs AI)" << std::endl;

    int modeChoice = 0;

    std::cin >> modeChoice;

    if (modeChoice != 0 && modeChoice != 1)
    {
        validateChoice();
    }
    else {
        return modeChoice;
    }

}

Player** PlayerInteraction::myPlayers()
{
    std::cout << "TIC TAC TOE" << std::endl;

    int modeChoice = validateChoice();

    std::string username;

    std::cout << "Enter the username" << std::endl;

    std::cin >> username;

    Player* playerOne = new Player(&username, true);

    Player* playerTwo = nullptr;

    if (modeChoice == 1)
    {
        std::string username2;

        std::cout << "Enter the username" << std::endl;

        std::cin >> username2;

        playerTwo = new Player(&username2, false);

        playerTwo->mode = false;

        playerTwo->playerFields = new int[3];

        playerOne->mode = false;

        playerOne->playerFields = new int[4];
    }
    else
    {
        std::cout << "Coming soon..." << std::endl;
    }

    return new Player * [2] {playerOne, playerTwo};
}

PlayerInteraction::PlayerInteraction()
{

}

void PlayerInteraction::fillTheBoard(Field*** myField)
{
    for (auto i = 0; i < 9; i++)
    {
        (*myField)[i] = new Field(i);
    }
}

void PlayerInteraction::operator()(Field** myField, Player* playerOne, Player* playerTwo)
{
    bool turnMeOn = true;

    for (auto i = 0; i < 9; i++)
    {
        Player* currentPlayer = nullptr;

        if (turnMeOn)
        {
            currentPlayer = playerOne;
        } 
        
        else
        {
            currentPlayer = playerTwo;
        }

        int fieldChoice;

        GameLogic gamelogic;

        while (true)
        {
            static int counter = 0;

            (*currentPlayer)();

            std::cout << currentPlayer->playerName << "'s turn!" << "(enter 0-8 to mark the squares)" << "[" << counter << "]" << std::endl;

            std::cin >> fieldChoice;

            if (fieldChoice < 0 || fieldChoice > 8 || gamelogic.checkForOccupied(myField,fieldChoice))
            {
                counter++;
                continue;
            }
            else {
                break;
            }
        }
        
        int f = gamelogic.occupy(myField, fieldChoice, currentPlayer);

        gamelogic.checkForWin(currentPlayer);

        soutTheBoard(myField);

        if (*(currentPlayer->won))
        {
            std::cout << currentPlayer->playerName << " won!" << std::endl;
            return;
        }

        if (turnMeOn)
        {
            turnMeOn = false;
        }
        else {
            turnMeOn = true;
        }
    }
}

void PlayerInteraction::soutTheBoard(Field** myField)
{
    for (int i = 0; i < 9; i++)
    {
        static int counter = 0;

        std::cout << myField[i]->chr;

        counter++;

        if (counter == 3)
        {
            counter = 0;

            std::cout << "\n";
        }
    }
}

