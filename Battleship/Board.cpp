#include "Board.h"
#include <iostream>

using namespace std;

Board::Board() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            board[i][j] = '-';
        }
    }
}

void Board::printBoard() {
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << static_cast<char>('a' + i) << ' ';
        for (int j = 0; j < 10; ++j) {
            char displayChar = board[i][j];
            if (displayChar != 'M' && displayChar != 'X') {
                displayChar = '-';
            }
            cout << displayChar << ' ';
        }
        cout << endl;
    }
}

bool Board::placeShip(Ship* ship, char startX, int startY, bool isVertical) {
    int length = ship->getLength();
    int x = startX - 'a';
    int y = startY - 1;

    if (isVertical) {
        if (x < 0 || x >= 10 || y < 0 || y + length > 10) return false;
    }
    else {
        if (x < 0 || x + length > 10 || y < 0 || y >= 10) return false;
    }

    for (int i = 0; i < length; ++i) {
        if (isVertical) {
            if (board[x][y + i] != '-') return false;
        }
        else {
            if (board[x + i][y] != '-') return false;
        }
    }

    for (int i = 0; i < length; ++i) {
        if (isVertical) {
            board[x][y + i] = ship->getName()[0];
        }
        else {
            board[x + i][y] = ship->getName()[0];
        }
    }

    ships.push_back(ship);
    return true;
}

bool Board::receiveShot(char x, int y) {
    int row = x - 'a';
    int col = y - 1;

    if (row < 0 || row >= 10 || col < 0 || col >= 10) {
        return false;
    }

    char& cell = board[row][col];
    if (cell == '-') {
        cell = 'M';  //miss
        return false;
    }
    else if (cell != 'M' && cell != 'X') {
        for (auto& ship : ships) {
            if (ship->getName()[0] == cell) {
                ship->takeHit();
                if (ship->isSunk()) {
                    cout << ship->getName() << " has sunk!" << endl;
                }
                break;
            }
        }
        cell = 'X';  //hit
        return true;
    }

    return false;
}

bool Board::allShipsSunk() {
    for (auto& ship : ships) {
        if (!ship->isSunk()) {
            return false;
        }
    }
    return true;
}


