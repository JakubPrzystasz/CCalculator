#include "calculator.h"
#include <string.h>

/*CALCULATE MATH EXPRESSION*/
double calculate(char* expression) {
	int size = 0;
	char** expressionArray = 0;
	char** rnpExpression = 0;

	size = strlen(expression);
	expressionArray = parseExpression(expression, &size);
	rnpExpression = toRPN(expressionArray, &size);
	double result = 0;
	result = computeRPN(rnpExpression, &size);
	return result;
}