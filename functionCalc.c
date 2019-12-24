#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long factorial(int n)
{
	if (n == 0) // Base case
		return 1;
	else
		return (n * factorial(n - 1));
}

char* functionCalc(char** args, int type) {
	double value = 0;
	char tmp[100];
	char* result = 0;
	double arg = { atof(args[0]) };

	switch (type) {
	case 3:
		value = (double)factorial(arg);
		break;
	case 0:
		value = log(arg);
		break;
	case 4:
		value = sin(arg);
		break;
	}
	sprintf(tmp, "%lf", value);
	result = appendToString(result, tmp);
	return result;
}