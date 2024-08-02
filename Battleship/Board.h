#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Ship.h"
#include <vector>
using namespace std;

class Board
{
private:
	const int SIZE = 10; //
	vector<vector<char>>grid;
	vector<Ship*> ships;

	int letterToIndex(char letter) const;

public:
	Board();
	bool placeShip(Ship* ship, char xLetter, int y, bool vertical);
	bool receiveAttack(char xLetter, int y);
	void display() const;
};
#endif

