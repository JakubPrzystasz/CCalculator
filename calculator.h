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
	typedef char byte;

	bool isOperator(expType operator);
	byte getOperatorPriority(expType operator);
	byte getOperatorTie(expType operator);
	byte getFunction(char* expression);
	expType getExpType(char* expression);
	char** parseString(char* expression,size_t* sizeOfArray);
	char** toPostfix(char** array, size_t* sizeOfArray);
	char* calculateValue(char** args, expType operator);
	double calculateString(char* expression);
	double calculatePostfix(char** array, size_t* sizeOfArray);

#endif
