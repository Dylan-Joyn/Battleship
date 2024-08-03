# Battleship
This is a c++ version of Battleship, the board game. There are two players and each player takes turns attack each others boards untl they sink all of their ships.

"Board"
Board shows the entire board but not the ships, so that each player does not know where each others ships are at. This class also determines if a ship was hit or not. Also checks if all the ships have sunk to display the winner.

"Player"
Player class is for each player, you can input your name in the code to customize it better or not. getBoard() is used to reference that player's board

"Ship"
This class makes the ships, gets the names of them, shows the length, records hits taken, and sees if it sunk

"AircraftCarrier", "Battleship", "Destroyer", "Cruiser"
These are also classes but they are derived from the Ship class. They hold the length of each ship
