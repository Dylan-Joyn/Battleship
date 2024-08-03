#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <string>

using namespace std;

class Ship {
private:
    string name;
    int length;
    int hits;

public:
    Ship(const string& name, int length);
    string getName() const;
    int getLength() const;
    void takeHit();
    bool isSunk() const;
};

class AircraftCarrier : public Ship {
public:
    AircraftCarrier() : Ship("Aircraft Carrier", 5) {}
};

class Battleship : public Ship {
public:
    Battleship() : Ship("Battleship", 4) {}
};

class Destroyer : public Ship {
public:
    Destroyer() : Ship("Destroyer", 3) {}
};

class Cruiser : public Ship {
public:
    Cruiser() : Ship("Cruiser", 2) {}
};

#endif



