// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Ship.h"
#include "Board.h"

using namespace std;

void placeShips(Player& player) {
    cout << player.getName() << " place your ships on the board." << endl;

    vector<Ship*> ships = {
        new AircraftCarrier(),
        new Battleship(),
        new Destroyer(),
        new Cruiser()
    };

    for (auto& ship : ships) {
        bool success = false;
        while (!success) {
            char x;
            int y;
            char orientation;
            cout << "Placing " << ship->getName() <<" " << ship->getLength() << " squares" << endl;
            cout << "Enter starting coordinate (example a5) ";
            cin >> x >> y;
            cout << "Enter orientation (h for horizontal, v for vertical) ";
            cin >> orientation;
            bool isVertical = (orientation == 'v');
            success = player.getBoard().placeShip(ship, x, y, isVertical);
            if (!success) {
                cout << "Invalid placement. Try again." << endl;
            }
        }
    }
}

void takeShot(Player& attacker, Player& defender) {
    char x;
    int y;
    cout << attacker.getName() << " it's your turn to attack" << endl;
    cout << "Enter coordinate to attack (example a5): ";
    cin >> x >> y;

    bool hit = defender.getBoard().receiveShot(x, y);
    if (hit) {
        cout << "Hit" << endl;
    }
    else {
        cout << "Miss" << endl;
    }

    defender.getBoard().printBoard();
}

bool gameWon(Player& player) {
    return player.getBoard().allShipsSunk();
}

int main() {
    Player player1("Player 1");
    Player player2("Player 2");

    placeShips(player1);
    placeShips(player2);

    while (true) {
        takeShot(player1, player2);
        if (gameWon(player2)) {
            cout << player1.getName() << " wins" << endl;
            break;
        }

        takeShot(player2, player1);
        if (gameWon(player1)) {
            cout << player2.getName() << " wins" << endl;
            break;
        }
    }

}





