#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

int main(int argc, char** argv)
{
	if (argc > 1) {
		char* expression = 0;
		expression = appendToString(expression, argv[1]);
		char** expressionArray = 0;
		double x = 0;
		x = calculate(expression);
		printf("RESULT:\n%.2lf\n", x);
	}
	return 0;
}
