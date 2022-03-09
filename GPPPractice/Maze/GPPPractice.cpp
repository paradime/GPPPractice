#include <iostream>
#include "GameState.h"

int main(int argc, char* argv[])
{
    GameState* Game = new GameState();
    printf("Escape the Maze.\n");
    while(!Game->HasWon)
    {
        Game->PrintMap();
        printf("Where next? (n e s w)");
        char in;
        std::cin >> in;
        switch (in)
        {
        case 'n':
            Game->HandleNorth();
            break;
        case 'e':
            Game->HandleEast();
            break;
        case 's':
            Game->HandleSouth();
            break;
        case 'w':
            Game->HandleWest();
            break;
        default:
            break;
        }
    }
    printf("You escaped!\n");
    return 0;
}
