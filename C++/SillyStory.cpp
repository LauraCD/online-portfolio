/**************************************************
 Project: Silly Story 01
 The story is made with data stored in variables, 
 getting user input, displaying data to the screen
 and doing simple calculations with variables.
**************************************************/
#include <iostream>
#include <string>
using namespace std;
int main() {
	const string unit = "C++ Programming";
	string studentName;
	string tutorName;
	int numStudent;
	int numResults;
	//User Info
	cout << "Please enter the following for a personalised adventure" << endl;
	cout << "Your first name: ";
	cin >> studentName;
	cout << "Your tutor's first name: ";
	cin >> tutorName;
	cout << "Number of students in your class: ";
	cin >> numStudent;
	cout << "***and finally***" << endl;
	cout << "A number positive number less than the class size: ";
	cin >> numResults;
	system("pause");
	system("CLS");
	//new variables
	int pass = numStudent - numResults;
	int otherStudents = numStudent - 1;
	//Story
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                     PROGRAMMING CLASS                      " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "" << endl;
	cout << "Everyone warned you, ";
	cout << studentName;
	cout << "." << endl;
	cout << "We told you, that picking this unit - ";
	cout << unit;
	cout << " - was a mistake. Not only do you have to figure out coding, but you also have to deal with ";
	cout << otherStudents;
	cout << " coding geeks." << endl;
	cout << "Sure, they're all cool people, but they're also REALLY smart, which doesn't really work in your favour does it?" << endl;
	cout << "Especially not when you realise, that, in this class of ";
	cout << numStudent;
	cout << " students, only ";
	cout << pass;
	cout << " will actually pass." << endl;
	cout << "AND out of those, students, only around ";
	cout << numResults;
	cout << " will actually get a High Distinction." << endl;
	system("pause");
	cout << "~(*-*)~" << endl;
	system("pause");
	cout << "SCARYYYYYYYYYY, right?" << endl;
	system("pause");
	cout << "But lucky you, ";
	cout << studentName;
	cout << "! You have ";
	cout << tutorName;
	cout << " as a tutor! UwU" << endl;
	cout << "..." << endl;
	cout << "Maybe you do have a chance of passing with a good grade after all..." << endl;
	cout << "Who knows..." << endl;
	system("pause");
	cout << "Miracles do sometimes happen..." << endl;
	cout << "(^-^) hehehe" << endl;
	system("pause");
	cout << "Just kidding!";
	system("pause");
	system("CLS");
	cout << "I believe in you ";
	cout << studentName;
	cout << "!" << endl;
	system("pause");
	cout << ":)" << endl;

	system("pause");
	return 0;
}
