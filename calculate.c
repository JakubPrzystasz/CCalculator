#include "calculator.h"

/*CALCULATE MATH EXPRESSION*/
double calculate(char* expression, int* length) {
	char** expressionArray = parseExpression(expression, length);
	expressionArray = toRPN(expressionArray, length);
	double result = computeRPN(expressionArray, length);
	return result;
}