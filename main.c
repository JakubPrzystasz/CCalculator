#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
int main(int argc, char** argv)
{
	char* expression = 0;
	expression = appendToString(expression, "sin(21)");
	printf("Result: {%lf}\n",calculateString(expression));

	return 0;
}
