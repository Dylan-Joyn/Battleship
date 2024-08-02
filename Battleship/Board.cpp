#include "Board.h"
#include <iostream>
using namespace std;
int Board::letterToIndex(char letter) const {
    return letter - 'a';
}

Board::Board() : grid(SIZE, vector<char>(SIZE, ' ')) {}

bool Board::placeShip(Ship* ship, char xLetter, int y, bool vertical) {
    int x = letterToIndex(xLetter);
    if (x < 0 || x >= SIZE || y < 1 || y > SIZE) return false;
    y--;

    if (vertical) {
        if (x + ship->getLength() > SIZE) return false;
        for (int i = 0; i < ship->getLength(); ++i) {
            if (grid[x + i][y] != ' ') return false;
        }
        for (int i = 0; i < ship->getLength(); ++i) {
            grid[x + i][y] = ship->getName()[0];
        }
    }
    else {
        if (y + ship->getLength() > SIZE) return false;
        for (int i = 0; i < ship->getLength(); ++i) {
            if (grid[x][y + i] != ' ') return false;
        }
        for (int i = 0; i < ship->getLength(); ++i) {
            grid[x][y + i] = ship->getName()[0];
        }
    }
    ships.push_back(ship);
    return true;
}

bool Board::receiveAttack(char xLetter, int y) {
    int x = letterToIndex(xLetter);
    if (x < 0 || x >= SIZE || y < 1 || y > SIZE) return false;
    y--;

    if (grid[x][y] == ' ' || grid[x][y] == 'X' || grid[x][y] == 'O') {
        grid[x][y] = 'O';
        return false;
    }
    else {
        char hitShip = grid[x][y];
        grid[x][y] = 'X';
        for (auto ship : ships) {
            if (ship->getName()[0] == hitShip) {
                ship->takeHit();
                if (ship->isSunk()) {
                    cout << ship->getName() << " has sunk" << endl;
                }
                break;
            }
        }
        return true;
    }
}

void Board::display() const {
    cout << "  ";
    for (int i = 1; i <= SIZE; ++i) {
        cout << i << ' ';
    }
    cout << endl;

    for (int i = 0; i < SIZE; ++i) {
        cout << char('a' + i) << ' ';
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}
