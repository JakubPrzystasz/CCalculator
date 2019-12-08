#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

	void freeArray(char** array, size_t size);
	void printArray(char** array, int* count);
	char* appendToString(char* string, char* value);
    char** popArray(char** array, int* count,bool deleteValue);
	char** appendToArray(char** array, char* string, int* count);
	char** insertToArray(char** array, char* string, int* count, int index);
	char** editInArray(char** array, char* string, int* count, int index);
	char** removeInArray(char** array, int* count, int index);
	char** parseExpression(char* expression, int* length);
	char** toRPN(char** expressionArray, int* length);
	char* doMath(int operator,char* arg1, char* arg2);
	int getOperator(char* expression);
	int getOperatorPriority(int operator);
	int getOperatorTie(int operator);
	bool isFunction(char* expression);
	bool isNumber(char* expression);
	bool isDigit(char expression);
	double computeRPN(char** expressionArray, int* length);
	double calculate(char* expression);

#endif
