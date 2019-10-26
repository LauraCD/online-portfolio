/**************************************************
Project: MasterMind TG
Author: Laura Chauca Diaz
Purpose: Board Class File
**************************************************/
#include "Board.h"
Board::Board() {

}

Board::Board(char level, char elements, string guess, string code, int guesses) {
	//set code size
	if (level == '0') {
		skillLevel = "Initiate";
		codeLength = 4;
		numGuesses = 10;
	}
	else if (level == '1') {
		skillLevel = "Pick-pocket";
		codeLength = 5;
		numGuesses = 12;
	}
	else if (level == '2') {
		skillLevel = "Master Thief";
		codeLength = 6;
		numGuesses = 14;
	}
	//set  code elements
	if (elements == '0') {
		codeElements = "{0, 1, 2, 3, 4, 5, 6, 7}";
	}
	else if (elements == '1') {
		codeElements = "{A, B, C, D, E, F, G, H, I, J, K, L}";
	}
	else if (elements == '2') {
		codeElements = "{!, @, #, $, %, ^, &, *, (, ), =, +, <, >, ?, /}";
	}
	numGuesses -= guesses;
	//check if code is entered
	if (guess.size() == code.size()) {
		checkGuess(guess, code);
	}

	//display board info
	cout << getBoardInfo();

	//display board
	displayGuess(guess);

}

Board::~Board() {
	//clear all variables
	skillLevel = "";
	codeLength = 0;
	numGuesses = 0;
	codeElements = "";
	guessBoard.clear();
}

// ACCESSOR FUNCTIONS
string Board::askForGuess(string question) { return playerGuess; }
string Board::getSkillLevel() { return skillLevel; }
int Board::getLength() { return codeLength; }
string Board::getElements() { return codeElements; }
int Board::getNumGuess() { return numGuesses; }
string Board::getBoardInfo() {
	// returns a formatted string
	stringstream boardInfo;
	boardInfo << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	boardInfo << "\n  Skill Level: " << getSkillLevel();
	boardInfo << "\n  Code Length: " << getLength();
	boardInfo << "\n  Elements: " << getElements();
	boardInfo << "\n  Guesses left: " << getNumGuess();
	boardInfo << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
	return boardInfo.str();
}

//MUTATOR FUNCTIONS
void Board::checkGuess(string guess, string code) {
	codeClues.clear();
	int black = 0;
	int white = 0;
	int empty = 0;
	//checking all correct elements in correct place
	for (int i = 0; i < code.size(); i++) {
		if (guess.at(i) == code.at(i)) {
			black += 1;
		}
		else {
			//checking correct elements in wrong place
			for (int j = 0; j < code.size(); j++) {
				if (i != j && guess.at(i) == code.at(j) && guess.at(i) != guess.at(j)) {
					white += 1;
				}
			}
		}
	}
	///for aesthetic purposes of board
	empty = code.size() - black - white;

	//clues for player
	for (int b = 0; b < black; b++) {
		codeClues.push_back("o");
	}
	for (int w = 0; w < white; w++) {
		codeClues.push_back("?");
	}
	for (int e = 0; e < empty; e++) {
		codeClues.push_back(" ");
	}

	//create or add to the board
	guessBoard.push_back("\n ");
	guessBoard.push_back("| |  ");
	for (int i = 0; i < guess.size(); i++) {
		string element = "";
		element.assign(1, guess[i]);
		guessBoard.push_back("[");
		guessBoard.push_back(element);
		guessBoard.push_back("] ");
	}
	guessBoard.push_back("\t:|:\t");
	///transform clue vector to string
	for (int i = 0; i < codeClues.size(); i++) {
		guessBoard.push_back(codeClues[i]);
	}
	guessBoard.push_back("  | |");
}

void Board::displayGuess(string guess) {
	//save data
	ofstream fileToWrite("GameBoard.txt", ios::app);
	if (fileToWrite.is_open()) {
		for (const auto &e : guessBoard) fileToWrite << e;
	}
	else {
		cout << "\nFile not found!";
	}
	/// remember to close the file
	fileToWrite.close();

	//display the game board
	ifstream fileToRead("GameBoard.txt");
	if (fileToRead.is_open()) {
		cout << endl;
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			cout << line << "\n";
		}
	}
	/// remember to close the file
	fileToRead.close();
}
