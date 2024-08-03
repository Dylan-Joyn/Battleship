#include "Ship.h"
using namespace std;

Ship::Ship(const string& name, int length) : name(name), length(length), hits(0) {}

string Ship::getName() const {
    return name;
}

int Ship::getLength() const {
    return length;
}

void Ship::takeHit() {
    if (hits < length) {
        ++hits;
    }
}

bool Ship::isSunk() const {
    return hits >= length;
}

