#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calculator.h"

int main(int argc, char** argv)
{

	char* expression = 0;
	expression = appendToString(expression, "sin5");
	double x = 0;
	x = calculate(expression);
	printf("RESULT:\n%.2lf\n", x);

	return 0;
}
