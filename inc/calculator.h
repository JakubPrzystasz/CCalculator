#include <stdbool.h>
#ifndef CALCULATOR_H
#define CALCULATOR_H
	double compute(char* expression);
	bool isNumber(char* expression);
	char **parseExpression(char* exp);
	char **appendArray(char** array,char* string,int* count);
	static void freeArray(char** array, size_t size);
#endif //CALCULATOR_H
