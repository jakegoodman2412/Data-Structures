#include "Infix.h"
#include <iostream>
#include <math.h>


//Expression Parser
int infixParser::stackBuilder(string expressionStr){
	char charStack;
	int digitStack;
	int finalResult;
	infixParser parserObject;



	for (int i = 0; i < expressionStr.size(); i++) {

		charStack = expressionStr[i];

		if (isdigit(charStack))
		{
			digitStack = charStack - 48;//accounting for character ASCII value
			parserObject.operandStack.push(digitStack);
		}


		else {
			switch (charStack) {

			case('('):
			{
				parserObject.operatorStack.push(charStack);
			}
			break;
			case(')'):
			{
				try {
					if (parserObject.operatorStack.top() == '(') {
						throw "Empty contents";
					}
				}
				catch (exception& e) {
					cout << e.what() << endl;
				}
			}
			break;
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

		parserObject.expressionEval();
	}
	finalResult = parserObject.operandStack.top();
	return finalResult;
}

//evaluate the expressions and send results back to stack
void infixParser::expressionEval() {

	int operandLeft;
	int operandRight;
	int expressionVal;
	char operatorVal;

	operandRight = operandStack.top();
	operandStack.pop();

	operandLeft = operandStack.top();
	operandStack.pop();

	operatorVal = operatorStack.top();
	operatorStack.pop();
	switch (operatorVal)
	{
	case ('+'):
	{
		expressionVal = operandLeft + operandRight;
		cout << operandLeft << " + " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);

	}
	break;

	case ('-'):
	{
		expressionVal = operandLeft - operandRight;
		cout << operandLeft << " - " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);
	}
	break;

	case ('%'):
	{
		expressionVal = operandLeft % operandRight;
		cout << operandLeft << " % " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);
	}
	break;
	case ('*'):
	{
		expressionVal = operandLeft * operandRight;
		cout << operandLeft << " * " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);

	}
	break;


	case ('/'):
	{
		expressionVal = operandLeft / operandRight;
		cout << operandLeft << " / " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);

	}
	break;

	case ('^'):
	{
		expressionVal = pow(operandLeft, operandRight);
		cout << operandLeft << " ^ " << operandRight << " = " << expressionVal << endl;
		operandStack.push(expressionVal);

	}
	break;

	}
}



