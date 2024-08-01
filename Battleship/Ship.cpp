#include "Ship.h"
using namespace std;
Ship::Ship(string name, int length)
	: name(name), length(length), hitsTaken(0) {}

string Ship::getName() const {
	return name;
}

int Ship::getLength() const {
	return length;
}

void Ship::takeHit() {
	hitsTaken++;
}

bool Ship::isSunk() const {
	return hitsTaken >= length;
}

AircraftCarrier::AircraftCarrier()
	: Ship("Aircraft Carrier", 5) {}

Battleship::Battleship()
	: Ship("Battleship", 4) {}

Destroyer::Destroyer()
	: Ship("Destroyer", 3) {}

Cruiser::Cruiser()
	: Ship("Cruiser", 2) {}
