#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdint.h>
#include <stdbool.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

	/* Calculator */

	typedef enum objectType {
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
	} objectType;

	typedef char byte;

	bool isOperator(objectType operator);
	byte getOperatorPriority(objectType operator);
	byte getOperatorTie(objectType operator);
	byte getFunction(char* string);
	objectType getObjectType(char* string);
	char** parseString(char* string,size_t* sizeOfArray);
	char** toPostfix(char** array, size_t* sizeOfArray);
	double calculateValue(char** args, objectType operator);
	double calculateString(char* string);
	double calculatePostfix(char** array, size_t* sizeOfArray);

#endif
