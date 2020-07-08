#include <stack>
#include <string> 
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "infix.h"
using namespace std;

int main() {
	Evaluator eval;
	string strLeft;
	string strRight;
	string expressionStr("4*2&&0");

	//does an initial error check
	eval.errorCheck(expressionStr);
	//checking to see if a comparison operator is used
	//if so, will need to return a boolean value. if not, an int will be returned
	bool compCheckVal = eval.compOpCheck(expressionStr);
	/*This if statement seperates the expression string into two substrings then two
	substrings are compared using the calculateC function which returns if the expression is true or false
	and then each are compared to the binary operator being used*/
	if (compCheckVal) {
		if (expressionStr.find("&&") != string::npos) {
			strLeft = expressionStr.substr(0, expressionStr.find("&&", 0));
			strRight = expressionStr.substr((expressionStr.find("&&") + 2));
			bool resultLeft = eval.calculateC(strLeft);
			bool resultRight = eval.calculateC(strRight);

			if (resultLeft && resultRight) {
				cout << "Both sides have the same boolean result, so result would be: True" << endl;
			}
			else {
				if (resultRight == false) {
					cout << "Right side is false, so result would be: False" << endl;
				}
				else {
					cout << "Left side is false, so result would be: False" << endl;
				}
			}
		}


		else if (expressionStr.find("||") != string::npos) {
			strLeft = expressionStr.substr(0, expressionStr.find("||", 0));
			strRight = expressionStr.substr((expressionStr.find("||") + 2));
			bool resultLeft = eval.calculateC(strLeft);
			bool resultRight = eval.calculateC(strRight);

			if (resultLeft || resultRight) {
				if (resultLeft == true) {
					cout << " Left side of the equation makes the expression: True" << endl;
				}
				else {
					cout << "Right side of the equation makes the expression: True" << endl;
				}
			}
			else {
				cout << "Both sides are false" << endl;
			}
		}
		else {// if no binary operator is present then proceed with a normal evaluation
			eval.calculateC(expressionStr);
		}
	}

	else {
		if (expressionStr.find("&&") != string::npos) {
			strLeft = expressionStr.substr(0, expressionStr.find("&&", 0));
			cout << "test: " << strLeft << endl;
			strRight = expressionStr.substr((expressionStr.find("&&") + 2));
			int resultLeft = eval.eval(strLeft);
			int resultRight = eval.eval(strRight);

			if (resultLeft == resultRight) {
				cout << "Both sides have the same boolean result, so result would be: True" << endl;
			}
			else {
				cout << "The sides are not equal to each other" << endl;
			}
		}


		else if (expressionStr.find("||") != string::npos) {
			strLeft = expressionStr.substr(0, expressionStr.find("||", 0));
			strRight = expressionStr.substr((expressionStr.find("||") + 2));
			bool resultLeft = eval.eval(strLeft);
			bool resultRight = eval.eval(strRight);

			if (resultLeft || resultRight) {
				if (resultLeft == true) {
					cout << " Left side of the equation makes the expression: True" << endl;
				}
				else {
					cout << "Right side of the equation makes the expression: True" << endl;
				}
			}
			else {
				cout << "Both sides are false" << endl;
			}
		}
		else {// if no binary operator is present then proceed with a normal evaluation
			eval.calculateC(expressionStr);
		}
	}

	return 0;
}
