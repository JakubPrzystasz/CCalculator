#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>

/* SPRAWDZ CZY CIAG JEST OPERATOREM */
Operator getOperator(char* expression) {
	if (strlen(expression) > 1) { return -1; }
	switch (expression[0])
	{
	case '+':
		return plus;
	case '-':
		return minus;
	case '*':
		return multiply;
	case '/':
		return divide;
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

	return undefined;
}