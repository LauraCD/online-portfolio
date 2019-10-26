#pragma once
/**************************************************
Project: MasterMind TG
Author: Laura Chauca Diaz
Purpose: Driver Header File
**************************************************/
#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Board.h"
#include "Player.h"
using namespace std;

// Variables
///for Board info
int codeElements;
int skillLevel;
int numGuess;
int totalGuess;
///for Player info
int gameWin;
int score;

///for game loop(s)
bool isGameOver;
bool hasGuessedCode;

int lose;
int win;

string name;
string playerGuess;
string currentCode;
int codeLength;
string codeDoc;
vector<string> codeList;

string askForString(string question);
int baseScore(char level, char elements);
char askForChar(string question);

// Game functions
void runMenu();
void displayTitle();
void displayText(string myFileName);
void gameOver();
void playGame();
void updateWin();
void updateLose();
void createCode(int level, int elements);
void setCodeLists(string myFileName, int codeSize);

#endif
