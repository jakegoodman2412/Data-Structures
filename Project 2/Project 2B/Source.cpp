//Jake Goodman & Deivid Guerrero 
//Project 2B
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Binary_Tree.h"

using namespace std; 


int main() {
	binaryTree treeObject;
	binaryTreeNode* nodeObject;
	map<char, string> morseMap;
	string morseString;
	string morseCode;
	char morseLetter;
	ifstream fileInput;
	ifstream fin("morse_code.txt");

	//intro message to program
	cout << "Welcome to our Morse Code Program!" << endl;
	//opening input file
	if (!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	cout << "Building out your Morse Code Binary Tree..." << endl;
	
	//reading file line by line and building out tree
	while (getline(fin, morseString)) {
		morseLetter = morseString[0];
		morseCode = morseString.substr(1);
		treeObject.InsertWrapper(morseLetter, morseCode);
		morseMap.insert(pair<char, string>(morseLetter, morseCode));
	}
	//exit out of file once we no longer need it
	fileInput.close();

	char userInput = 'a';
	//access UI part of program
	//allow end user to choose if they'd like to encode or a decode a message of their choosing
	//exit out by pressing 'q' or 'Q'
	while (toupper(userInput) != 'Q') {
		cout << "Please select from the below options on if you'd like to either encode a message into Morse Code ";
		cout << "or decode a Morse Code message into text!" << endl;

		cout << "Type in 'E' to proceed with the Encode option" << endl;
		cout << "Type in 'D' to proceed with the Decode option" << endl;
		cout << "Type in 'Q' to quit the program" << endl;
		cin >> userInput;
		if (toupper(userInput) == 'E') {
			treeObject.encode(morseMap);//call our encoce function which just needs the already built map
		}
		else if (toupper(userInput) == 'D') {
			treeObject.decode(treeObject);//call our decode function while passing in the BT class object
		}
		else if (toupper(userInput) == 'Q') {
			cout << "Thanks for using our program!" << endl;
		}
		else {
			cout << "Please select a valid input! ('E', 'D', or 'Q')" << endl;
		}

	}
	
	return 0;
}
