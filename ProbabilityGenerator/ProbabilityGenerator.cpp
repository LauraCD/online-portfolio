/**************************************************
 Project: Probability Generator
**************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
//variables
string askForString(string question);
string intToString(int n);
int oneDie[6] = { 1,2,3,4,5,6 };
int twoDice[11] = { 2,3,4,5,6,7,8,9,10,11,12 };
///number lists
string oneResults;
string twoResults;
string threeResults;
string fourResults;
string fiveResults;
string sixResults;
string sevenResults;
string eightResults;
string nineResults;
string tenResults;
string elevenResults;
string twelveResults;
///collection variables
vector<string> tallyData;
vector<string> tallyResults;
//game functions
void displayTitle();
void runMenu();
void displayText();
void readFile(string myFileName);
void createLists();
void generateTable();
void displayInfo(vector<string> vectorName);
void saveTable();
void loadTable();
void oneDieTally();
void twoDiceTally();
void updateData(vector<string>);

int main() {
	// seed randoms
	srand(unsigned(time(NULL)));
	//start program
	runMenu();
	//wait and exit
	system("pause");
	return 0;
}

void displayTitle() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\t\t Probability Generator\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void runMenu() {
	system("CLS");
	string optChoice;
	//listing options
	displayTitle();
	cout << "[E] End testing program\n";
	cout << "[1] Display 'about' information\n";
	cout << "[2] Read and store data from files\n";
	cout << "[3] Generate a dice tally table\n";
	cout << "[4] Save tally statistics to a file\n";
	cout << "[5] Load tally statistics from a file\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//gaining user input
	optChoice = askForString("Which option would you like?: ");
	//loop
	do {
		if (optChoice == "E" || optChoice == "e") {
			cout << "\nThank you for testing this application\n";
		}
		else if (optChoice == "1") {
			displayText();
		}
		else if (optChoice == "2") {
			createLists();
		}
		else if (optChoice == "3") {
			generateTable();
		}
		else if (optChoice == "4") {
			saveTable();
		}
		else if (optChoice == "5") {
			loadTable();
		}
		else {
			cout << "\nPlease enter a valid command.\n\n";
			system("pause");
			system("CLS");
			runMenu();
		}
	} while (optChoice == "");
}

///opt 1
void displayText() {
	system("CLS");
	readFile("TallyAbout.txt");
	system("pause");
	system("CLS");
	runMenu();
}

///opt 2
void createLists() {
	cout << "Data loading from savedTallyData.txt...\n";
	//display saved data
	readFile("savedTallyData.txt");
	updateData(tallyData);
	//end process
	system("pause");
	runMenu();
}

///opt 3
void generateTable() {
	int numDice;
	int numNeededRolls;
	tallyResults.clear();
	//number of dice
	do {
		cout << "\nHow many dice would you like to roll? (1-2): ";
		cin >> numDice;
		if (numDice < 1 || numDice > 2) {
			cout << "Please enter a valid number";
		}
	} while (numDice < 1 || numDice > 2);
	//number of rolls
	do {
		cout << "How many rolls are required? (1-10): ";
		cin >> numNeededRolls;
		if (numNeededRolls <= 0 || numNeededRolls > 10) {
			cout << "Please enter a valid number\n";
		}
	} while (numNeededRolls <= 0 || numNeededRolls > 10);

	int numRolls = numNeededRolls * 10;

	//table
	if (numDice == 1) {
		do { //one die table
			oneDieTally();
			numRolls -= 1;
		} while (numRolls > 0);

	}
	else { //two dice table
		do {
			twoDiceTally();
			numRolls -= 1;
		} while (numRolls > 0);
	}
	//response
	string dice = intToString(numDice);
	string rolls = intToString(numNeededRolls * 10);
	string response;
	tallyResults.push_back("\nYou rolled " + dice + " dice, " + rolls + " times.\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	if (numDice == 1) {
		tallyResults.push_back("  1: " + oneResults + "\n  2: " + twoResults + "\n  3: " + threeResults + "\n  4: " + fourResults + "\n  5: " + fiveResults + "\n  6: " + sixResults + "\n");
	}
	else {
		tallyResults.push_back("  2: " + twoResults + "\n  3: " + threeResults + "\n  4: " + fourResults + "\n  5: " + fiveResults + "\n  6: " + sixResults + "\n  7: " + sevenResults + "\n  8: " + eightResults + "\n  9: " + nineResults + "\n 10: " + tenResults + "\n 11: " + elevenResults + "\n 12: " + twelveResults + "\n");
	}
	displayInfo(tallyResults);
	system("pause");
	runMenu();
}

void oneDieTally(){
	int num;
	num = oneDie[rand() % 6];
	switch (num) {
	case 1: oneResults += "*";
		break;
	case 2: twoResults += "*";
		break;
	case 3: threeResults += "*";
		break;
	case 4: fourResults += "*";
		break;
	case 5: fiveResults += "*";
		break;
	case 6: sixResults += "*";
	}
}

void twoDiceTally() {
	int num;
	num = twoDice[rand() % 11];
	switch (num) {
	case 2: twoResults += "*";
		break;
	case 3: threeResults += "*";
		break;
	case 4: fourResults += "*";
		break;
	case 5: fiveResults += "*";
		break;
	case 6: sixResults += "*";
		break;
	case 7: sevenResults += "*";
		break;
	case 8: eightResults += "*";
		break;
	case 9: nineResults += "*";
		break;
	case 10: tenResults += "*";
		break;
	case 11: elevenResults += "*";
		break;
	case 12: twelveResults += "*";
	}
}

///opt 4
void saveTable() {
	displayInfo(tallyResults);
	string answer = askForString("Do you want to save this file? (y/n): ");
	do {
		if (answer == "y" || answer == "Y") {
			ofstream fileToWrite("savedTallyData.txt", ios::app);
			if (fileToWrite.is_open()) {
				for (const auto &e : tallyResults) fileToWrite << e;
			}
			else {
				cout << "\nFile not found!";
			}
			// remember to close the file
			fileToWrite.close();
			cout << "\nThese statistics are now saved.\n";
			system("pause");
			system("CLS");
			runMenu();
		}
		else if (answer == "n" || answer == "N") {
			cout << "\nThese statistics were not saved.\n";
			system("pause");
			system("CLS");
			runMenu();
		}
		else {
			cout << "Please enter valid command.";
		}
	} while (answer != "n" & answer != "N" & answer != "y" & answer != "Y");
}

///opt 5
void loadTable() {
	updateData(tallyData);
	system("CLS");
	readFile("savedTallyData.txt");
	system("pause");
	runMenu();
}

void readFile(string myFileName) {
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
		system("pause");
		runMenu();
	}
	// remember to close the file
	fileToRead.close();
}

string askForString(string question) {
	// gets a line response (spaces included)
	string userInput = "";
	while (userInput == "") {
		cout << question;
		getline(cin, userInput);
	}
	return userInput;
}

void displayInfo(vector<string> vectorName) {
	for (int i = 0; i < vectorName.size(); i++)
		cout << vectorName[i];
	cout << endl;
}

string intToString(int n) {
	std::string str = std::to_string(n);
	return str;
}

void updateData(vector<string> n) {
	n.clear();
	ifstream fileToRead("savedTallyData.txt");
	if (fileToRead.is_open()) {
		string line = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line);
			if (line != "") {
				n.push_back(line);
			} 
		}
	}
}
