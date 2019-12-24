#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdint.h>
#include <stdbool.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

	/* Calculator */


typedef enum day { sun, mon, tue, wed, thu, fri, sat } day;

	typedef enum expType {
		number,
		operator,
		bracket,
		function,
		delimiter,
		undefined,
	} expType;

	typedef enum Operator {
		plus,
		minus,
		multiply,
		divide,
		power,
		modulo,
		leftBracket,
		rightBracket,
		comma,
	} Operator;
	
	char** parseExpression(char* expression,size_t* sizeOfArray);
	char** toRPN(char** expressionArray, int* length);
	char* doMath(int operator,char* arg1, char* arg2);
	expType getType(char* expression);
	Operator getOperator(char* expression);
	int getOperatorPriority(int operator);
	int getOperatorTie(int operator);
	int getFunction(char* expression);
	bool isNumber(char* expression);
	bool isDigit(char expression);
	double computeRPN(char** expressionArray, int* length);
	double calculate(char* expression);

#endif
