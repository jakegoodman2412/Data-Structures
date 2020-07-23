#include "Binary_Tree.h"
#include <iostream>
#include <sstream>

//Main insert function that builds out the tree
void binaryTree::Insert(binaryTreeNode*&node, char morseLetter, string morseCode) {

	//cout << morseCode << "\t";
	if (node == NULL) {
		node = new binaryTreeNode();
	}

	if (morseCode.size() == 0) {
		//cout << "string has been emptied" << endl;
		node->morseLetter = morseLetter;
	}

	else {
		if (morseCode[0] == '_') {
			Insert(node->right, morseLetter, morseCode.substr(1));
			
		}
		else {
			Insert(node->left, morseLetter, morseCode.substr(1));
		}
	}
//	cout << "done" << endl;
}

//feeds the main insert function
void binaryTree::InsertWrapper(char morseLetter, string morseCode) {

	Insert(root, morseLetter, morseCode);
}

//just an adhoc print function as needed for validation
void binaryTree::Print(binaryTreeNode*& node) {
	cout << root->left->right->morseLetter << endl;
}


//passes through the already built out map
//and then uses the user input to look for map matches
void binaryTree::encode(const map<char,string> myMap) {
	string str;
	cout << "Please enter a word you would like to have encoded!" << endl;
	cin >> str;
	string output;
	cout << "Original Input: " << str << endl;
	for (int i = 0; i < str.size(); i++) {
		char c = tolower(str.at(i));
		if (!isalpha(c)) {
			cout << "Only alpha characters are allowed!" << endl;
			encode(myMap);
		}
		output += myMap.at(c) + " ";

	}
	cout << "Morse Code Output: " << output << endl;
}

//feeds main search function
char binaryTree::findWrapper(string target) {
	//cout << "test 2: " << endl;
	return(find(root, target));
}
//main search function that will be used to decode messages
char binaryTree::find(binaryTreeNode*& node, string target) {

	//cout << "target test: " << target << endl;

	if (node == NULL) {
		return NULL;
	}

	char c = target[0];

	if (c == '_') {
		return(find(node->right, target.substr(1)));
	}
	else if (c == '.') {
		return(find(node->left, target.substr(1)));
	}
	else {
		return(node->morseLetter);

	}
}

//just takes in already existing BT class object
//then asks user for message and will use the find functions
//to decode
void binaryTree::decode(binaryTree object) {
	
	cout << "Please enter in the message you would like to decode" << endl;
	string input;
	cin.ignore();
	getline(cin, input);
	stringstream ss(input);
	string singleMorseWord;
	cout << "Decoded Message: ";
	while (ss >> singleMorseWord) {
		cout << object.findWrapper(singleMorseWord);
	}
	cout << endl;
}