#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

/*CALCULATE MATH EXPRESSION*/
double calculate(char* expression, int* length) {
	char** expressionArray = parseExpression(expression, length);
	expressionArray = toPOSTFIX(expressionArray, length);
	double result = compute(expressionArray, length);
	return result;
}