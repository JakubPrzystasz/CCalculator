#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Get exp type stored in string */
expType getExpType(char* expression) {
	
	//Bypass null reference
	if (expression == NULL) {
		return undefined;
	}

	//Length of expression
	size_t expLength = strlen(expression);

	if (expLength < 1) { return undefined; }

	//Number
	if (isNumber(expression)) {
		return number;
	}

	//Operator
	if (expLength == 1) {
		switch (expression[0])
		{
			case '+':
				return addition;
			case '-':
				return subtraction;
			case '*':
				return multiplication;
			case '/':
				return division;
			case '^':
				return power;
			case '%':
				return modulo;
			case '(':
				return leftBracket;
			case ')':
				return rightBracket;
			case ',':
				return comma;
		}
	}

	

	return undefined;
}