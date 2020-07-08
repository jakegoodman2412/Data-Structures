#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include "infix.h"

using namespace std;

int Evaluator::eval(string token)
{
	stack <char> operators;
	stack<int>operands;


	stringstream expression(token);
	char s;
	int number, number2;
	string digit, digit2,doubleOper;
	stringstream convert;
	while (expression >> s) {

		if (isOperator(s)) {

			if (s == ')') {
					while (operators.top() != '(') {
						string oper3;
						char oper = operators.top();
						operators.pop();

						if (!operators.empty()) {
							if (operators.top() ==  '+', '-' , '!' && operators.top() == oper) {
								cout << "Found double operator" << endl;
								char oper2 = operators.top();
								auto oper3 = string(1, oper) + oper2;
								operators.pop();
								oper = '0';
							}
						}

						int num2 = operands.top();
						operands.pop();
						int num1 = operands.top();
						operands.pop();

						int goToFcn;
						if (oper == '0') {
							goToFcn = calculate(oper3);
							cout << num1 << " " << oper3 << " " << num2 << endl;
						}
						else {
							goToFcn = calculate(oper);
							cout << num1 << " " << oper << " " << num2 << endl;

						}
						switch (goToFcn) {
						case 1:
							operands.push(calculateArithmetic(num1, num2, oper));
							break;
						case 3:
							operands.push(calculatePre(num1, oper));
							break;
						case 4:
							operands.push(calculateNot(num1));
							break;
						case 7:
							operands.push(calculatePre(num1, oper3));
							break;

						default:
							cout << "Did not find operand" << endl;
							break;
						}
					}			
				operators.pop();
			}
			else {

				
				while (!operators.empty() && precedence(operators.top()) >= precedence(s) && operands.size() >= 2) {
					cout << precedence(operators.top()) << " and "<< precedence(s) << endl;
					string oper3;
					char oper = operators.top();
					operators.pop();

					if (!operators.empty()) {
						if (operators.top() == '+', '-', '!' && operators.top() == oper) {
							cout << "Found double operator" << endl;
							char oper2 = operators.top();
							auto oper3 = string(1, oper) + oper2;
							operators.pop();
							oper = '0';
						}
					}

					int num2 = operands.top();
					operands.pop();
					int num1 = operands.top();
					operands.pop();

					int goToFcn;
					if (oper == '0') {
						goToFcn = calculate(oper3);
						cout << num1 << " " << oper3 << " " << num2 << endl;
					}
					else {
						goToFcn = calculate(oper);
						cout << num1 << " " << oper << " " << num2 << endl;

					}
					switch (goToFcn) {
					case 1:
						operands.push(calculateArithmetic(num1, num2, oper));
						break;
					case 3:
						operands.push(calculatePre(num1, oper));
						break;
					case 4:
						operands.push(calculateNot(num1));
						break;
					case 7:
						operands.push(calculatePre(num1, oper3));
						break;

					default:
						cout << "Did not find operand" << endl;
						break;
					}
				
				}
				//pushes the operator, if it is less than the precedence of the top operator in the stack
				operators.push(s); 
			}
		}
		else {

			if (!isdigit(expression.peek())) {		
				digit = s;
				number = stoi(digit);
				operands.push(number);
				continue;
			}

			digit2 = s;

			while(isdigit(expression.peek())) {
				expression >> s;
				digit2 += s;
				if (!isdigit(expression.peek())) {
					number2 = stoi(digit2);
					operands.push(number2);
				}
			}

		}
	}



	while (!operators.empty()) {

		string oper3;
		char oper = operators.top();
		operators.pop();

		if (!operators.empty()) {
			if (operators.top() == '+', '-', '!' && operators.top() == oper) {
				cout << "Found double operator" << endl;
				char oper2 = operators.top();
				oper3 = string(1, oper) + oper2;
				operators.pop();
				oper = '0';
			}
		}

		int num2 = operands.top();
		operands.pop();
		int num1 = operands.top();
		operands.pop();
		int goToFcn;
		if (oper == '0') {
			goToFcn = calculate(oper3);
			cout << num1 << " " << oper3 << " " << num2 << endl;
		}
		else {
			goToFcn = calculate(oper);
			cout << num1 << " " << oper << " "  << num2 << endl;

		}
		switch (goToFcn) {
		case 1:
			operands.push(calculateArithmetic(num1, num2, oper));
			break;
		case 3:
			operands.push(calculatePre(num1, oper));
			break;
		case 4:
			operands.push(calculateNot(num1));
			break;

		case 7:
			operands.push(calculatePre(num1, oper3));
			break;

		default:
			cout << "Did not find operand" << endl;
			break;
		}
		
	}


	return operands.top();
}

bool Evaluator::calculateC(string c)
{
	Evaluator eval;
	char charStack;
	int digitStack;
	string strLeft;
	string strRight;
	int resultLeft;
	int resultRight;
	//infixParser parserExecuter;

	/*going through and evaluating if expression string has comparison operators or not
	 if not, it will go through the normal evaluation process

	 In the comparison operators, we are grabbing substrings on each side of the operator and then running
	 those separately through the function that will evaluate each expression*/
	if (c.find(">=") != string::npos) {
		strLeft = c.substr(0, c.find(">=", 0));
		strRight = c.substr((c.find(">=") + 2));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft >= resultRight) {
			cout << resultLeft << " is greater than or equal to " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is not greater than or equal to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find("<=", 0) != string::npos) {
		strLeft = c.substr(0, c.find("<=", 0));
		strRight = c.substr((c.find("<=") + 2));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft <= resultRight) {
			cout << resultLeft << " is less than or equal to " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is not less than or equal to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find("<", 0) != string::npos) {
		strLeft = c.substr(0, c.find("<", 0));
		strRight = c.substr((c.find("<") + 1));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft < resultRight) {
			cout << resultLeft << " is less than " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is not less than to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find(">", 0) != string::npos) {
		strLeft = c.substr(0, c.find(">", 0));
		strRight = c.substr((c.find(">") + 1));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft > resultRight) {
			cout << resultLeft << " is greater than " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is not greater than to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find("==", 0) != string::npos) {
		strLeft = c.substr(0, c.find("==", 0));
		strRight = c.substr((c.find("==") + 2));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft == resultRight) {
			cout << resultLeft << " is equal to " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is not equal to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find("!=", 0) != string::npos) {
		strLeft = c.substr(0, c.find("!=", 0));
		strRight = c.substr((c.find("!=") + 2));
		resultLeft = eval.eval(strLeft);
		resultRight = eval.eval(strRight);
		if (resultLeft != resultRight) {
			cout << resultLeft << " is not equal to " << resultRight << endl;
			return true;
		}
		else {
			cout << resultLeft << " is equal to " << resultRight << endl;
			return false;
		}
	}
	else if (c.find("0",0) != string::npos) {
		return false;
	
	}
	else if (c.find("1", 0) != string::npos) {
		return true;

	}
	else {
		cout << "Expression Result: " << eval.eval(c) << endl;
	}
}

int Evaluator::precedence(char c)
{
	switch (c)
	{
	case ')':
		return 9;
	case '(':
		return 9;
	case '!':
		return 8;
	case '++':
		return 8;
	case '--':
		return 8;
	case '-':
		//how to differentiate negative and minus
		return 8;
	case '^':
		return 7;
	case '*':
		return 6;
	case '/':
		return 6;
	case '%':
		return 6;
	case '+':
		return 5;

	case '>':
		return 4;
	case '>=':
		return 4;
	case '<':
		return 4;
	case '<=':
		return 4;
	case '==':
		return 3;
	case '!=':
		return 3;
	case '&&':
		return 2;
	case '||':
		return 1;

	default:
		return 0;
	}
}

int Evaluator::calculate(char c)
{
	vector<char>arithmetic = {'+', '-','*','/','%','^'};

	if (find(arithmetic.begin(), arithmetic.end(), c) != arithmetic.end())
		return 1;
	cout << c << endl;
	switch(c) {
	case '>':
		return 2;
	case '<':
		return 2;
	case '-':
		return 3;
	case '!':
		return 4;
	default:
		return 0;
	}
}

int Evaluator::calculate(string c)
{

	vector<string> op = { ">=" , "<=" , "==" , "!="  };
	vector<string> op2 = { "&&" , "||"  };
	vector<string> op3 = { "--" , "++" };

	if(find(op.begin(), op.end(), c) != op.end())
		return 5;
	if (find(op2.begin(), op2.end(), c) != op2.end())
		return 6;
	if (find(op3.begin(), op3.end(), c) != op3.end())
		return 7;

	return 0;
}


int Evaluator::calculateArithmetic(int num1, int num2, char c)
{
	switch (c) {
	case '+':
		cout << num1 << " + " << num2 << endl;
		return (num1 + num2);
	case '-':
		cout << num1 << " - " << num2 << endl;
		return (num1 - num2);
	case '*':
		return (num1 * num2);
	case '/':
		if (num2 == 0) {
			cout << "Division by 0 error" << endl;
			exit(0);
		}
		return (num1 / num2);
	case '%':
		return (num1 % num2);
	case '^':
		return (pow(num1,num2));
	default:
		return 0;
	}
}


bool Evaluator::calculateNot(int num1)
{
	return !num1;
}

int Evaluator::calculatePre(int num1, string c)
{
	if (c == "++") {
		return (++num1);
	}
	else if (c == "--") {
	
		return (--num1);
	}
	else {
		return 0;
	}

}

int Evaluator::calculatePre(int num1, char c)
{
	if (c == '-')
		return -num1;
	else 
		return 0;
}

bool Evaluator::isOperator(char c)
{
	switch (c)
	{
	case ')':
		return true;
	case '(':
		return true;
	case '!':
		return true;
	case '++':
		return true;
	case '--':
		return true;
	case '-'://negative or minus
		return true;
	case '^':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	case '%':
		return true;
	case '+':
		return true;
	case '>':
		return true;
	case '>=':
		return true;
	case '=':
		return true;
	case '<':
		return true;
	case '<=':
		return true;
	case '==':
		return true;
	case '!=':
		return true;
	case '&&':
		return true;
	case '||':
		return true;

	default: //Is an int or operand
		return false;
	}
}

void Evaluator::errorCheck(string token) {
	string strToChar;
	//Can't start with these operators
	vector<string> firstOp = { ")", "<", ">", ">=", "<=", "==", "!=" };
	stringstream cc;
	cc << token[0];
	cc >> strToChar;
	//Using these lines to check for any errors in the equation

	if (find(firstOp.begin(), firstOp.end(), strToChar) != firstOp.end()) { //checks for any starting binary operator or closing parenthesis
		cout << "Expression can't start with a '" << strToChar << "' @ char: 0" << endl;
		exit(0);
	}

	if (token.find("&&&", 0) != string::npos) { //checks for more than 3 binary AND's
		cout << "Two or more binary operators in a row @ char " << (token.find("&&&", 0) != string::npos) << endl;
		exit(0);
	}
	else if (token.find("|||", 0) != string::npos) {//checks for more than 3 binary OR's
		cout << "Two or more binary operators in a row @ char " << (token.find("|||", 0) != string::npos) << endl;
		exit(0);
	}

}