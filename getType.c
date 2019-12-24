#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>
#include <string.h>

/* Return type of expression */
expType getType(char* expression) {

	//Length of expression
	size_t expLength = strlen(expression);

	if (expLength < 1) { return undefined; }

	if (isNumber(expression)) {
		return number;
	}

	Operator _operator = getOperator(expression[0]);

	if (expLength == 1 && _operator < 6) {
		return operator;
	}

	if (expLength == 1 && _operator >= 6 && _operator <= 7) {
		return bracket;
	}

	if (expLength == 1 && _operator == comma) {
		return delimiter;
	}

	return function;
}