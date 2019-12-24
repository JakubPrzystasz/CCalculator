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

	expType getExpType(char* expression);
	char** parseExpression(char* expression,size_t* sizeOfArray);
	char** toRPN(char** array, size_t* sizeOfArray);

	double computeRPN(char** array, size_t* sizeOfArray);

	char* basicCalculation(char** args,expType operator);
	char* functionCalc(char** args,int function);
	int getOperatorPriority(expType operator);
	int getOperatorTie(expType operator);
	int getFunction(char* expression);
	bool isOperator(expType token);
	double calculate(char* expression);

#endif
