#include <stack>
#include <string> 
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "Infix.h"

using namespace std;

int main() {

	string expressionStr = "1+2>=1+1";//input expression string to evaluate
	char charStack;
	int digitStack;
	string strLeft;
	string strRight;
	int resultLeft;
	int resultRight;
	infixParser parserExecuter;

	/*going through and evaluating if expression string has comparison operators or not
	 if not, it will go through the normal evaluation process
	 
	 In the comparison operators, we are grabbing substrings on each side of the operator and then running 
	 those separately through the function that will evaluate each expression*/
	if (expressionStr.find(">=") != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find(">=", 0));
		strRight = expressionStr.substr((expressionStr.find(">=") + 2));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft >= resultRight) {
			cout << resultLeft << " is greater than or equal to " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is not greater than or equal to " << resultRight << endl;
		}
	}
	else if (expressionStr.find("<=", 0) != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find("<=", 0));
		strRight = expressionStr.substr((expressionStr.find("<=") + 2));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft <= resultRight) {
			cout << resultLeft << " is less than or equal to " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is not less than or equal to " << resultRight << endl;
		}
	}
	else if (expressionStr.find("<", 0) != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find("<", 0));
		strRight = expressionStr.substr((expressionStr.find("<") + 1));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft < resultRight) {
			cout << resultLeft << " is less than " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is not less than to " << resultRight << endl;
		}
	}
	else if (expressionStr.find(">", 0) != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find(">", 0));
		strRight = expressionStr.substr((expressionStr.find(">") + 1));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft < resultRight) {
			cout << resultLeft << " is greater than " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is not greater than to " << resultRight << endl;
		}
	}
	else if (expressionStr.find("==", 0) != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find("==", 0));
		strRight = expressionStr.substr((expressionStr.find("==") + 2));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft == resultRight) {
			cout << resultLeft << " is equal to " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is not equal to " << resultRight << endl;
		}
	}
	else if (expressionStr.find("!=", 0) != string::npos) {
		strLeft = expressionStr.substr(0, expressionStr.find("!=", 0));
		strRight = expressionStr.substr((expressionStr.find("!=") + 2));
		resultLeft = parserExecuter.stackBuilder(strLeft);
		resultRight = parserExecuter.stackBuilder(strRight);
		cout << "Left Side Value: " << resultLeft << endl;
		cout << "Rigth Side Value: " << resultRight << endl;
		if (resultLeft != resultRight) {
			cout << resultLeft << " is not equal to " << resultRight << endl;
		}
		else {
			cout << resultLeft << " is equal to " << resultRight << endl;
		}
	}
	else {
		cout << "Expression Result: " << parserExecuter.stackBuilder(expressionStr) << endl;

	}

	return 0;
}



