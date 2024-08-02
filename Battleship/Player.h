#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
private:
    string name;
    Board board;

public:
    Player(string name);
    string getName() const;
    Board& getBoard();
    void attack(Player& opponent, char xLetter, int y);
};

#endif


