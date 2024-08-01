#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <string>
using namespace std;

class Ship {
protected:
    string name;
    int length;
    int hitsTaken;

public:
    Ship(string name, int length);
    string getName() const;
    int getLength() const;
    void takeHit();
    bool isSunk() const;
};

class AircraftCarrier : public Ship {
public:
    AircraftCarrier();
};

class Battleship : public Ship {
public:
    Battleship();
};

class Destroyer : public Ship {
public:
    Destroyer();
};

class Cruiser : public Ship {
public:
    Cruiser();
};

#endif


