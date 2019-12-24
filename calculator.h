#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdint.h>
#include <stdbool.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

	/* Calculator */

	typedef enum expType {
		number,
		addition,
		subtraction,
		multiplication,
		division,
		power,
		modulo,
		leftBracket,
		rightBracket,
		comma,
		function,
		undefined
	} expType;

	char** parseExpression(char* expression,size_t* sizeOfArray);
	expType getExpType(char* expression);
	char** toRPN(char** array, size_t* sizeOfArray);


	char* doMath(int operator,char* arg1, char* arg2);
	int getOperatorPriority(expType operator);
	int getOperatorTie(expType operator);
	int getFunction(char* expression);
	bool isNumber(char* expression);
	bool isDigit(char expression);
	double computeRPN(char** expressionArray, int* length);
	double calculate(char* expression);

#endif
