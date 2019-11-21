#include <stdbool.h>
#include <stdlib.h>
#define CALCULATOR_H

	static void freeArray(char** array, size_t size);
	int appendToString(char* string, char* tail);
	int pushBackArray(char** array, char* string, int* count);
	int editArray(char** array, char* string, int* count, int index);
	int removeInArray(char** array, int* count, int index);
	int popArray(char** array, int* count);
	int insertToArray(char** array, char* string, int* count, int index);
	int parseExpression(char* expression, int* length);
	bool isNumber(char* expression);
	bool isDigit(char* expression);
	int toPOSTFIX(char** expressionArray, int* length);
	double compute(char** expressionArray, int* length);
	int doMath(int operator,char* arg1, char* arg2);
	int getOperator(char* expression);
	int getOperatorPriority(int* operator);
	bool isFunction(char* expression);
	double compute(char** expressionArray, int* length);