#pragma once
#include <vector>

struct Coordinates
{
    int col;
    int row;
};

enum room_info
{
    empty,
    wall,
    start,
    finish,
    unseen,
    MAX
};

class GameState
{
// Variables
public:
    GameState();

    bool HasWon;
private:
    Coordinates CurrentCoordinates{};
    std::vector<std::vector<room_info>>* Board;
    std::vector<std::vector<room_info>>* Map;

// Functions
public:
    // input
    void HandleNorth();
    void HandleEast();
    void HandleSouth();
    void HandleWest();

    // input validation
    bool NorthIsValid();
    bool EastIsValid();
    bool SouthIsValid();
    bool WestIsValid();

    void PrintMap();
private:
    //constructor methods
    std::vector<std::vector<room_info>>* CreateBoard();
    std::vector<std::vector<room_info>>* CreateMap();

    void PrintBoard(std::vector<std::vector<room_info>> BoardOrMap);
    void UpdateMap();

    bool NorthIsInBounds();
    bool EastIsInBounds();
    bool SouthIsInBounds();
    bool WestIsInBounds();
};
