/**************************************************
Project: MasterMind TG
Author: Laura Chauca 
Purpose: Driver Class File
**************************************************/
#include "Main.h"
#include "Board.h"
#include "Player.h"

int main() {
	gameWin = 0;
	score = 0;

	lose = 0;
	win = 0;

	displayText("Instructions.txt");
	// Name
	displayTitle();
	name = askForString(" What's your name, thief? ");
	cout << " Welcome, " << name << ".\n";

	runMenu();

	system("pause");
	return 0;
}

void playGame() {

	//initialise variables 
	isGameOver = false;
	hasGuessedCode = false;

	//main game loop
	while (!isGameOver) {
		currentCode.clear();
		codeList.clear();
		playerGuess.clear();
		//guesses used
		numGuess = 0;

		//create code
		createCode(skillLevel, codeElements);

		while (!hasGuessedCode) {
			//set board parameters
			displayTitle();
			Board::Board(skillLevel, codeElements, playerGuess, currentCode, numGuess);

			///ask player to guess
			playerGuess = askForString("What do you think the code is?: ");
			// convert to one case to match words in the list
			transform(playerGuess.begin(), playerGuess.end(), playerGuess.begin(), toupper);

			///loop including extra functions
			if (playerGuess == "p" || playerGuess == "P") {
				system("CLS");
				displayText("Instructions.txt");
			}
			if (playerGuess == "q" || playerGuess == "Q" || playerGuess == "r" || playerGuess == "R") {
				skillLevel = ' ';
				codeElements = ' ';
				//exit loops
				hasGuessedCode = true;
			}
			if (playerGuess.size() > 1) {
				if (playerGuess.size() == currentCode.size()) {
					//reduce guess number by 1
					numGuess++;
					//check guess and bring feedback
					if (playerGuess == currentCode) {
						displayTitle();
						Board::Board(skillLevel, codeElements, playerGuess, currentCode, numGuess);
						//correct
						cout << "\n\n Good job. You guessed the code, " << currentCode << ", correctly.\n";
						gameWin++;
						win++;
						lose = 0;
						score += baseScore(skillLevel, codeElements) - (numGuess * 6);
						///exit loops
						hasGuessedCode = true;
					} //out of guesses
					else if (numGuess > totalGuess) {
						cout << "\n\n You ran out of time! You had to leave with nothing!\n\n";
						cout << "The code was " << currentCode << endl;
						lose++;
						score -= 100;
						///exit loops
						hasGuessedCode = true;
					}
				}
				else {
					//not enough for code
					cout << " Don't waste time!\n";
					system("pause");
				}
			}
		}
		//delete file - guesses
		ofstream os("GameBoard.txt");

		//show player info
		Player::Player(name, score, gameWin);

		if (playerGuess == "q" || playerGuess == "Q") {
			isGameOver = true;
		}
		else if (playerGuess == "r" || playerGuess == "R") {
			displayTitle();
			runMenu();
		}
		else {
			gameOver();
		}
	}
	//goodbye message
	cout << "Hope to see you around soon, thief.\n";
}

void runMenu() {

	//select code length and elements
	skillLevel = askForChar("What level safe would you like to crack? \n (0 => Initiate, 1 => Pick-pocket, 2 => Master thief): ");
	codeElements = askForChar("What elements would you like to use? \n (0 => Numbers, 1 => Letters, 2 => Symbols): ");

	playGame();
}

void displayTitle() {
	system("CLS");
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "                   MasterMind - The Thieves Guild\n";
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void createCode(int level, int elements) {
	// seed randoms
	srand(unsigned(time(NULL)));
	if (level == '0') {
		codeLength = 4;
		totalGuess = 10;
	}
	else if (level == '1') {
		codeLength = 5;
		totalGuess = 12;
	}
	else if (level == '2') {
		codeLength = 6;
		totalGuess = 14;
	}
	//set  code elements
	if (elements == '0') {
		codeDoc = "CodesNumber.txt";
	}
	else if (elements == '1') {
		codeDoc = "CodesLetter.txt";
	}
	else if (elements == '2') {
		codeDoc = "CodesSymbol.txt";
	}

	//set code list
	setCodeLists(codeDoc, codeLength);

	//choose a particular code
	int myRand;
	myRand = rand() % codeList.size();
	///chosen code
	currentCode = codeList[myRand];
}

//set list of codes
void setCodeLists(string myFileName, int codeSize) {
	// load the words and hints from a file
	fstream fileToRead(myFileName);
	if (fileToRead.is_open()) {
		string line = "";
		string code = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			code = line.substr(0, codeSize);
			// add to appropriate lists
			codeList.push_back(code);
		}
	}
	// remember to close file
	fileToRead.close();
}

void gameOver() {
	string ans;

	//play again?
	while (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
		ans = askForString("Would you like to move onto the next mark? (y/n): ");
		if (ans == "y" || ans == "Y") {
			updateWin();
			updateLose();
			//repeat all loops
			hasGuessedCode = false;
		}
		else if (ans == "n" || ans == "N") {
			isGameOver = true;
		}
	}
}

void updateWin() {
	if (win == 5) {
		if (skillLevel == '0' || skillLevel == '1') {
			string ans;
			while (ans != "y" && ans != "Y" && ans != "n" && ans != "N") {
				ans = askForString("Would you like to move onto a more difficult mark? (y/n)");
				if (ans == "y" || ans == "Y") {
					if (skillLevel == '0') {
						skillLevel = '1';
					}
					else {
						skillLevel = '2';
					}
					currentCode.clear();
				}
			}
		}
		win = 0;
	}
}

void updateLose() {
	if (lose == 5) {
		if (skillLevel == '1' || skillLevel == '2') {
			cout << "Let's try something a bit easier, shall we?\n";
			system("pause");
			if (skillLevel == '2') {
				skillLevel = '1';
			}
			else {
				skillLevel = '0';
			}
			currentCode.clear();
		}
		lose = 0;
	}

}

//create base Score number
int baseScore(char level, char elements) {
	int a = 0;
	int b = 0;

	if (level == '0') {
		a = 100;
	}
	else if (level == '1') {
		a = 200;
	}
	else if (level == '2') {
		a = 300;
	}
	//set  code elements
	if (elements == '0') {
		b = 100;
	}
	else if (elements == '1') {
		b = 250;
	}
	else if (elements == '2') {
		b = 400;
	}
	int baseScore = a + b;

	return baseScore;
}


//display text from file
void displayText(string myFileName) {
	// open file for reading
	ifstream fileToRead(myFileName);
	if (fileToRead.is_open()) {
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			cout << line << "\n";
		}
	}
	else {
		cout << "\n File not found!\n";
	}
	// remember to close the file
	system("pause");
	fileToRead.close();
}

string askForString(string question) {
	// gets a line response (spaces included)
	string userInput = "";
	while (userInput == "") {
		cout << "\n " << question;
		cin >> userInput;
	}
	return userInput;
}

char askForChar(string question) {
	// ask a single letter response question
	char choice = ' ';
	while (choice != '0' && choice != '1' && choice != '2') {
		cout << "\n " << question;
		cin >> choice;
	}
	return tolower(choice);
}
