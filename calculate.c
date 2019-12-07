#include "calculator.h"
#include <string.h>

/*CALCULATE MATH EXPRESSION*/
double calculate(char* expression) {
	int size = 0;
	char** expressionArray = 0;
	char** rpnArray = 0;
	double result = 0;

	size = strlen(expression);
	printf("EXPRESSION:\n%s\n",expression);
	expressionArray = parseExpression(expression, &size);
	printf("PARSED EXPRESSION:\n");
	printArray(expressionArray, &size);
	rpnArray = toRPN(expressionArray, &size);
	printf("RPN EXPRESSION:\n");
	printArray(rpnArray, &size);
	result = computeRPN(rpnArray, &size);
	return result;
}