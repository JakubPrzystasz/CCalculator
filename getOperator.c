#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>

/* SPRAWDZ CZY CIAG JEST OPERATOREM */
int getOperator(char* expression) {
	if (strlen(expression) > 2) { return -1; }
	switch (expression[0])
	{
	case '+':
		return 0;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	case '^':
		return 4;
	case '%':
		return 5;
	case '(':
		return 6;
	case ')':
		return 7;
	case ',':
		return 8;
	}

	return -1;
}