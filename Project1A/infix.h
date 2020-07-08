#pragma once
#include<iostream>

using namespace std;

class Evaluator {

public:
	int eval(string token);
	bool calculateC(string c);
	int precedence(char c);
	int calculate(char c);
	int calculate(string c);
	int calculateArithmetic(int num1, int num2, char c);
	bool calculateNot(int num1);
	int calculatePre(int num1, string c);
	int calculatePre(int num1, char c);
	bool isOperator(char c);
	void errorCheck(string s);
};