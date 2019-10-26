/**************************************************
Project: MasterMind TG
Author: Laura Chauca Diaz
Purpose: Player Class File
**************************************************/
#include "Player.h"
Player::Player() {
	playerName = "";
	playerScore = 0;
	playerWins = 0;
}

Player::Player(string name, int score, int wins) {
	playerName = name;
	playerScore = score;
	playerWins = wins;

	cout << getPlayerStats();
}

Player::~Player() {

}

// ACCESSOR FUNCTIONS
string Player::getName() { return playerName; }
int Player::getWins() { return playerWins; }
int Player::getScore() { return playerScore; }
string Player::getPlayerStats() {
	// returns a formatted string
	stringstream playerStats;
	playerStats << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	playerStats << "\n  Thief name: " << getName();
	playerStats << "\n  Successful heists: " << getWins();
	playerStats << "\n  Loot: $" << getScore();
	playerStats << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return playerStats.str();
}
