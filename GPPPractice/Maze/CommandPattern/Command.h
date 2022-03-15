#pragma once
#include "../../Maze/GameState.h"

class Command
{
public:
    virtual void execute(GameState* state) = 0;
    virtual void undo(GameState* state) = 0;
};

class NorthCommand : public Command
{
public:
    void execute(GameState* state) override
    {
        state->HandleNorth();
    }
    void undo(GameState* state) override
    {
        state->HandleSouth();
    }
};

class SouthCommand : public Command
{
public:
    void execute(GameState* state) override
    {
        state->HandleSouth();
    }
    void undo(GameState* state) override
    {
        state->HandleNorth();
    }
};

class WestCommand : public Command
{
public:
    void execute(GameState* state) override
    {
        state->HandleWest();
    }
    void undo(GameState* state) override
    {
        state->HandleEast();
    }
};

class EastCommand : public Command
{
public:
    void execute(GameState* state) override
    {
        state->HandleEast();
    }
    void undo(GameState* state) override
    {
        state->HandleWest();
    }
};
