#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdint.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

	/* Calculator */

	typedef enum expType {
		tNumber,
		tAddition,
		tSubtraction,
		tSultiplication,
		tDivision,
		tPower,
		tModulo,
		tLeftBracket,
		tRightBracket,
		tComma,
		tFunction,
		tUndefined
	} expType;

	typedef struct _func {
		const char name[5];
		const unsigned short argsCount;
		const double(*func)(char*);
	} _func;

	char** parseExpression(char* expression,size_t* sizeOfArray);
	expType getExpType(char* expression);
	char** toRPN(char** array, size_t* sizeOfArray);


	int getOperatorPriority(expType operator);
	int getOperatorTie(expType operator);
	int getFunction(char* expression);

	double computeRPN(char** expressionArray, int* length);
	double calculate(char* expression);

#endif
