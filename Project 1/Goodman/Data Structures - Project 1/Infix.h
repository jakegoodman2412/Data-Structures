#pragma once
#include <stack>
#include <string>
using namespace std;

class infixParser
{
public:
	void expressionEval();
	stack <int> operandStack;
	stack <char> operatorStack;
	const string opString = "+-*/%^()[]{}";

	int precedence(char op) const {
		return opString.find(op);
	}
private:
	
};

