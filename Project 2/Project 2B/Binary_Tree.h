#pragma once
#include "morseCode.h"

struct binaryTreeNode
{

	char morseLetter;
	binaryTreeNode* left;
	binaryTreeNode* right;

	binaryTreeNode() : morseLetter(0), left(nullptr), right(nullptr) {}
};

class binaryTree {

public:

	binaryTree() : root(nullptr) {}
	void InsertWrapper(char morseLetter, string morseCode);
	char findWrapper(string target);
	void Print(binaryTreeNode*& node);
	void encode(const map<char, string> myMap, string str);
	char find(binaryTreeNode*& node, string target);
private:
	binaryTreeNode* root;
	void Insert(binaryTreeNode*& node, char morseLetter, string morseCode);

	//void to_vector(binaryTreeNode* root, vector<char>& morseLetVector);
	//char max(binaryTreeNode* local_root) const;
};




