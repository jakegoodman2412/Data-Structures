#include "Binary_Tree.h"
#include <iostream>
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

void binaryTree::InsertWrapper(char morseLetter, string morseCode) {

	Insert(root, morseLetter, morseCode);
}

void binaryTree::Print(binaryTreeNode*& node) {
	cout << root->left->right->morseLetter << endl;
}



void binaryTree::encode(const map<char,string> myMap, string str) {
	string output;
	cout << "Original Input: " << str << endl;
	for (int i = 0; i < str.size(); i++) {
		char c = tolower(str.at(i));
		if (!isalpha(c)) {
			cout << "Only alpha characters are allowed!" << endl;
			exit(1);
		}
		output += myMap.at(c) + " ";

	}
	cout << "Morse Code Output: " << output << endl;
}

char binaryTree::findWrapper(string target) {
	return(find(root, target));
}
char binaryTree::find(binaryTreeNode*& node, string target) {

	
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