#pragma once
/**************************************************
Project: MasterMind TG
Author: Laura Chauca Diaz
Purpose: Board Class Header
**************************************************/
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Board {
private:
	//variables
	string playerGuess;
	string skillLevel;
	int codeLength;
	string codeElements;
	vector<string> guessBoard;
	vector<string> codeClues;
	int numGuesses;

public:
	//constructors
	Board();
	Board(char skillLevel, char elements, string guess, string code, int guesses);

	//destructor
	~Board();

	//accessor functions
	string askForGuess(string question);
	string getSkillLevel();
	int getLength();
	string getElements();
	string getBoardInfo();
	int getNumGuess();

	//mutator functions
	void checkGuess(string guess, string code);
	void displayGuess(string guess);
};
#endif
