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
	string expressionStr("30+(2*3)");

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
			cout << "Both sides have the same boolean result" << endl;
		}
		else {
			cout << "Sides have different boolean result" << endl;
		}
	}
	else if (expressionStr.find("||") != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find("||", 0));
		strRight = expressionStr.substr((expressionStr.find("||") + 2));
		bool resultLeft = eval.calculateC(strLeft);
		bool resultRight = eval.calculateC(strRight);

		if (resultLeft || resultRight) {
			cout << "One side of the equation must be true" << endl;
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