#include "Infix.h"
#include <iostream>
#include <math.h>

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

