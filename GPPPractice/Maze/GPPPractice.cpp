#include <iostream>
#include <thread>

#include "GameState.h"
#include "CommandPattern/Command.h"

void ReplayGame(std::vector<Command*> commands)
{
    GameState* Game = new GameState();
    for (auto command : commands)
    {
        printf("\n");
        Game->PrintMap();
        command->execute(Game);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}
void CommandLoop()
{
    GameState* Game = new GameState();
    printf("Escape the Maze.\n");
    auto nc = NorthCommand();
    auto ec = EastCommand();
    auto sc = SouthCommand();
    auto wc = WestCommand();
    std::vector<Command*> commands = std::vector<Command*>();
    while(!Game->HasWon)
    {
        Game->PrintMap();
        printf("Where next? (n e s w) (u)ndo: ");
        char in;
        std::cin >> in;
        switch (in)
        {
        case 'n':
            commands.push_back(&nc);
            commands.back()->execute(Game);
            break;
        case 'e':
            commands.push_back(&ec);
            commands.back()->execute(Game);
            break;
        case 's':
            commands.push_back(&sc);
            commands.back()->execute(Game);
            break;
        case 'w':
            commands.push_back(&wc);
            commands.back()->execute(Game);
            break;
        case 'u':
            if (!commands.empty())
            {
                commands.back()->undo(Game);
                commands.pop_back();
            }
            break;
        default:
            break;
        }
    }
    printf("You escaped!\n");
    printf("Replaying game\n");
    ReplayGame(commands);
}

void OriginalLoop()
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
}

int main(int argc, char* argv[])
{
    CommandLoop();
    return 0;
}
