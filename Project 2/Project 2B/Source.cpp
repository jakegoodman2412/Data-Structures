#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include "Binary_Tree.h"

using namespace std; 



bool stringLenSort(morseClass s, morseClass t) {
	return s.morseCode.size() < t.morseCode.size();
}


int main() {
	string encodeInput("TEST");
	string decodeInput("__ _...");
	morseClass morseObject;
	binaryTree treeObject;
	binaryTreeNode* nodeObject;
	map<char, string> morseMap;
	string morseString;
	string morseCode;
	char morseLetter;
	ifstream fileInput;
	vector<morseClass> morseVector;
	ifstream fin("morse_code.txt");

	if (!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	while (getline(fin, morseString)) {
		/*morseObject.morseLetter = morseString[0];
		morseObject.morseCode = morseString.substr(1);*/
		morseLetter = morseString[0];
		morseCode = morseString.substr(1);
		treeObject.InsertWrapper(morseLetter, morseCode);
		morseMap.insert(pair<char, string>(morseLetter, morseCode));
		//morseVector.push_back(morseObject);
	}
	fileInput.close();

	//treeObject.encode(morseMap, encodeInput);
	//treeObject.Print(nodeObject);
	stringstream ss(decodeInput);
	string singleMorse;
	while (ss >> singleMorse) {
		cout << treeObject.findWrapper(singleMorse);
	}



	

	/*sort(morseVector.begin(), morseVector.end(), stringLenSort);
	for (int i = 0; i < morseVector.size(); i++) {
		cout << morseVector.at(i).morseCode << endl;
	}*/


	
	return 0;
}