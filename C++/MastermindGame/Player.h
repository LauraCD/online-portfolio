#pragma once
/**************************************************
Project: MasterMind TG
Author: Laura Chauca Diaz
Purpose: Player Class Header
**************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Player {
private:
	//variables
	string playerName;
	int playerScore;
	int playerWins;
	int numGames;
public:
	//constructors
	Player();
	Player(string name, int score, int wins);

	//destructor
	~Player();

	//accessor functions
	string getName();
	int getScore();
	int getWins();
	string getPlayerStats();

};

#endif
