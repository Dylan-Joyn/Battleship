#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& name)
    : name(name) {}

string Player::getName() const {
    return name;
}

Board& Player::getBoard() {
    return board;
}