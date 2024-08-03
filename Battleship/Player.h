#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>

class Player {
private:
    string name;
    Board board;

public:
    Player(const string& name);
    string getName() const;
    Board& getBoard();
};

#endif



