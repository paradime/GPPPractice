#include "GameState.h"
#include <iostream>

GameState::GameState()
{
    Board = CreateBoard();
    Map = CreateMap();
    UpdateMap();
    CurrentCoordinates.col = 0;
    CurrentCoordinates.row = 0;
    HasWon = false;
}

bool GameState::NorthIsValid()
{
    if(!NorthIsInBounds()) return false;
    return Board->at(CurrentCoordinates.row-1)[CurrentCoordinates.col] != wall;
}

bool GameState::EastIsValid()
{
    if(!EastIsInBounds()) return false;
    return Board->at(CurrentCoordinates.row)[CurrentCoordinates.col+1] != wall;
}

bool GameState::SouthIsValid()
{
    if(!SouthIsInBounds()) return false;
    return Board->at(CurrentCoordinates.row+1)[CurrentCoordinates.col] != wall;
}

bool GameState::WestIsValid()
{
    if(!WestIsInBounds()) return false;
    return Board->at(CurrentCoordinates.row)[CurrentCoordinates.col-1] != wall;
}

std::vector<std::vector<room_info>>* GameState::CreateBoard()
{
    return new std::vector<std::vector<room_info>>({
        {start, wall, empty, empty, empty},
        {empty, empty, empty, wall, empty},
        {empty, wall, empty, wall, empty},
        {empty, wall, wall, wall, finish}
    });
}
std::vector<std::vector<room_info>>* GameState::CreateMap()
{
    return new std::vector<std::vector<room_info>>({
        {unseen, unseen, unseen, unseen, unseen},
        {unseen, unseen, unseen, unseen, unseen},
        {unseen, unseen, unseen, unseen, unseen},
        {unseen, unseen, unseen, unseen, unseen},
    });
}

void GameState::UpdateMap()
{
    Map->at(CurrentCoordinates.row)[CurrentCoordinates.col] = Board->at(CurrentCoordinates.row)[CurrentCoordinates.col];
    if (NorthIsInBounds())
    {
        Map->at(CurrentCoordinates.row-1)[CurrentCoordinates.col] =
            Board->at(CurrentCoordinates.row-1)[CurrentCoordinates.col];
    }
    if (EastIsInBounds())
    {
        Map->at(CurrentCoordinates.row)[CurrentCoordinates.col+1] =
            Board->at(CurrentCoordinates.row)[CurrentCoordinates.col+1];
    }
    if (SouthIsInBounds())
    {
        Map->at(CurrentCoordinates.row+1)[CurrentCoordinates.col] =
            Board->at(CurrentCoordinates.row+1)[CurrentCoordinates.col];
    }
    if (WestIsInBounds())
    {
        Map->at(CurrentCoordinates.row)[CurrentCoordinates.col-1] =
            Board->at(CurrentCoordinates.row)[CurrentCoordinates.col-1];
    }
    HasWon = Board->at(CurrentCoordinates.row)[CurrentCoordinates.col] == finish;
}

bool GameState::NorthIsInBounds()
{
    return CurrentCoordinates.row != 0;
}

bool GameState::EastIsInBounds()
{
    return CurrentCoordinates.col != static_cast<int>(Board->at(CurrentCoordinates.row).size()) -1;
}

bool GameState::SouthIsInBounds()
{
    return CurrentCoordinates.row != static_cast<int>(Board->size()) -1;
}

bool GameState::WestIsInBounds()
{
    return CurrentCoordinates.col != 0;
}

void GameState::PrintMap() { PrintBoard(*Map); }

void GameState::PrintBoard(std::vector<std::vector<room_info>> BoardOrMap)
{
    int rowNum = 0;
    int colNum = 0;
    for (const auto& r : BoardOrMap)
    {
        for (room_info c : r)
        {
            std::string value;
            switch (c) {
                case empty: value = "_"; break;
                case wall: value = "[]"; break;
                case start: value = "s"; break;
                case finish: value = "f"; break;
                case unseen: value = "?"; break;
                case MAX: break;
                default: ;
            }
            if(CurrentCoordinates.row == rowNum && CurrentCoordinates.col == colNum)
            {
                value = "P";
            }
            std::cout << value << "\t";
            colNum += 1;
        }
        std::cout << std::endl;
        rowNum += 1;
        colNum = 0;
    }
}

void GameState::HandleNorth()
{
    if (!NorthIsValid()) { return; }
    CurrentCoordinates.row -= 1;
    UpdateMap();
}

void GameState::HandleEast()
{
    if(!EastIsValid()) { return; }
    CurrentCoordinates.col += 1;
    UpdateMap();
}

void GameState::HandleSouth()
{
    if(!SouthIsValid()) { return; }
    CurrentCoordinates.row += 1;
    UpdateMap();
}

void GameState::HandleWest()
{
    if(!WestIsValid()) { return; }
    CurrentCoordinates.col -= 1;
    UpdateMap();
}

