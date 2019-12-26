#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
int main(int argc, char** argv)
{
	char* string = 0;
	size_t size = 0;
	char** array = 0;

	array = appendToArray(array, "-2", &size);
	array = appendToArray(array, "2", &size);
	double x = calculateValue(array, subtraction);
	
	string = doubleToString(-44.34243);

	printf("%s\n", string);

	//printf("Result: {%lf}\n",calculateString(expression));

	return 0;
}
