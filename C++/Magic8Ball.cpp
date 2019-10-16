/**************************************************
 Project: Magic 8 Ball
**************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//game functions
void displayTitle();
void magic8Ball();
string askForString(string question);
string question;
const int maxResponses = 8;
string responses[8] = { "Yes", "Very doubtful", "Better not tell you now", "Outlook not so good", "Don't count on it", "My sources say no", "It is decidedly so", "Signs point to yes" };


int main() {
	const int maxResponses = 8;
	string responses[8] = {"Yes", "Very doubtful", "Better not tell you now", "Outlook not so good", "Don't count on it", "My sources say no", "It is decidedly so", "Signs point to yes"};
// activate the Magic 8 Ball
	magic8Ball();
// wait and exit
	system("pause");
	return 0;
}

void displayTitle() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\tMagic 8 Ball ~(*-*)~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void magic8Ball() {
	displayTitle();
	string name = "";
	name = askForString("What is your name, player? ");
	cout << "\nThank you, " ;
	cout << name;
	cout << ".\n";
	system("pause");
	system("CLS");
	displayTitle();
	//game loop
	do {
		cout << "Type your question or [Q] to quit.\n";
		cin >> question;
		if (question == "q" || question == "Q") {
			cout << "\nI hope you got the answers you were searching for.\n";
		}
		else {
			int answer = rand() % 8;
			cout << "\n" << responses[answer] << endl;
		}
	} while (question != "q" & question != "Q");

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
