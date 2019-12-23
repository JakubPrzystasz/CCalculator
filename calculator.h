#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdint.h>
#include <stdbool.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

/* Calculator */
	char** parseExpression(char* expression, int* length);
	char** toRPN(char** expressionArray, int* length);
	char* doMath(int operator,char* arg1, char* arg2);
	int getOperator(char* expression);
	int getOperatorPriority(int operator);
	int getOperatorTie(int operator);
	int getFunction(char* expression);
	bool isNumber(char* expression);
	bool isDigit(char expression);
	double computeRPN(char** expressionArray, int* length);
	double calculate(char* expression);

#endif
