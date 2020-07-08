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
	string expressionStr("1  && 1");

	//does an initial error check
	eval.errorCheck(expressionStr);

	/*This if statement seperates the expression string into two substrings then two
	substrings are compared using the calculateC function which returns if the expression is true or false
	and then each are compared to the binary operator being used*/
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

	return 0;
}