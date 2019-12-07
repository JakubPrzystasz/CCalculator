#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

int main(int argc, char** argv)
{
	char* expression = 0;
	expression = appendToString(expression,"-23+3");
	double x = 0;
	x = calculate(expression);
	printf("%lf\n",x);
	//if (argc > 1) {
	//	char* expression = 0;
	//	expression = appendToString(expression, argv[1]);
	//	int length = strlen(expression);
	//	double value = 0;
	//	value = calculate(expression, &length);
	//	printf("%lf", value);
	//}
	return 0;
}
