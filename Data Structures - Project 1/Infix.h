#pragma once
#include <stack>
#include <string>
using namespace std;

//simple class to hosue stacks and functions
class infixParser
{
public:
	void expressionEval();
	int stackBuilder(string expressionStr);
	stack <int> operandStack;
	stack <char> operatorStack;
	const string opString = "+-*/%^()[]{}";

	//precedence function inspired from class example
	int precedence(char op) const {
		return opString.find(op);
	}
private:
	
};

