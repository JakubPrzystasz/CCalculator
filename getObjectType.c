#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Get exp type stored in string */
objectType getObjectType(char* string) {
	
	//Bypass null reference
	if (string == NULL) {
		return undefined;
	}

	//Length of expression
	size_t expLength = strlen(string);

	if (expLength < 1) { return undefined; }

	//Number
	if (isNumber(string)) {
		return number;
	}

	//Operator
	if (expLength == 1) {
		switch (string[0])
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

	return function;
}