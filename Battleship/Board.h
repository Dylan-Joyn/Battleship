#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include <vector>
using namespace std;

class Board {
private:
    char board[10][10];
    vector<Ship*> ships;

public:
    Board();
    void printBoard();
    bool placeShip(Ship* ship, char startX, int startY, bool isVertical);
    bool receiveShot(char x, int y);
    bool allShipsSunk();
};

#endif


