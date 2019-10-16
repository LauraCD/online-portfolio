/**************************************************
 Project: Guess My Number
**************************************************/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//declare functions
void displayTitle();
void playGame();
string askForString(string question);
const string question = "\nI'm thinking of a number between 1-100.\nWhat do you think it is?";

int main() {
	int answer;
	//display the title
	displayTitle();
	//play the game
	playGame();

	cout << "\nPlay again? (1 = yes, 0 = no)\n";
	cin >> answer;
	if (answer == 1) {
		system("CLS");
		displayTitle();
			playGame();
	} else {
		system("pause");
		return 0;
	}
}

void displayTitle() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\tGuess My Number\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void playGame() {
	//local variables
	int secretNumber;
	secretNumber = rand() % 100 + 1;
	int guessNumber;
	//Game loop
	do {
		cout << question + "\n";
		cin >> guessNumber;
		if (guessNumber > secretNumber) {
			cout << "\nYour number is too high. Try again :)\n";
		}
		else if (guessNumber < secretNumber) {
			cout << "\nYour number is too low. Try again :)\n";
		}
		else {
			cout << "\nGood job! You guessed my number!\n";
		}
	} while (guessNumber != secretNumber);

}

string askForString(string question) {
	// gets a line response (spaces included)
	cin.ignore();
	string userInput = "";
	while (userInput == "") {
		cout << "\n " + question;
		getline(cin, userInput);
	}
	return userInput;
}
