#include <stack>
#include <string> 
#include <sstream>
#include <iostream>
#include "Infix.h"

using namespace std;

int main() {


	char charStack;
	int digitStack;
	string expressionStr = "20^5+3^2";
	infixParser parserObject;
	istringstream infix_token(expressionStr);
	string next_token;
	

	for (int i = 0; i < expressionStr.size(); i++) {
	
		charStack = expressionStr[i];

		if (isdigit(charStack))
		{
			digitStack = charStack - 48;
			parserObject.operandStack.push(digitStack);

		}

		else {
			
			switch (charStack) {

			case('('):
			{
				parserObject.operatorStack.push(charStack);
				cout << "Pushed " << charStack << " into the operator stack" << endl;
			}
			case('%'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{

					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;
			case('^'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{

					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;
			case('*'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{

					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;
			case('/'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{

					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;

			case('+'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{
					
					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;


			case('-'):
			{
				if (parserObject.operatorStack.empty())
				{
					parserObject.operatorStack.push(charStack);
				}
				else if (parserObject.precedence(charStack) > parserObject.precedence(parserObject.operatorStack.top())) {
					parserObject.operatorStack.push(charStack);
				}
				else
				{

					if (parserObject.operatorStack.top() == charStack) {
						parserObject.expressionEval();
						parserObject.operatorStack.push(charStack);
					}
					else {

						while (!parserObject.operatorStack.empty() && parserObject.precedence(charStack) < parserObject.precedence(parserObject.operatorStack.top()))
						{
							parserObject.expressionEval();
							parserObject.operatorStack.push(charStack);
						}
					}
				}
			}
			break;
			}

		}


	}

	while (!parserObject.operandStack.empty() && !parserObject.operatorStack.empty()) {

		cout << "Stack Contents: " << parserObject.operandStack.top() << endl;
		parserObject.expressionEval();
	}

	return 0;
}