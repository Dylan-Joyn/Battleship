#include "Player.h"
#include <iostream>

Player::Player(string name) : name(name) {}

string Player::getName() const {
    return name;
}
Board& Player::getBoard() {
    return board;
}

void Player::attack(Player& opponent, char xLetter, int y) {
    if (opponent.getBoard().receiveAttack(xLetter, y)) {
        cout << "Hit" << std::endl;
    }
    else {
        cout << "Miss" << std::endl;
    }
}
