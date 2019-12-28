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
	size_t strLength = strlen(string);

	if (strLength < 1) { return undefined; }

	//Number
	if (isNumber(string)) {
		return number;
	}

	//Operator and function
	if (strLength == 1) {
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
			case '!':
				return factorial;
		}
	}

	//Function

	if (strcmp("log", string) == 0) {
		return flog;
	}

	if (strcmp("sin", string) == 0) {
		return fsin;
	}

	if (strcmp("cos", string) == 0) {
		return fcos;
	}

	if (strcmp("tg", string) == 0) {
		return ftg;
	}

	if (strcmp("ctg", string) == 0) {
		return fctg;
	}

	return undefined;
}