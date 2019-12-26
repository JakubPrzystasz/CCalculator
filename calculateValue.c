#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double calculateValue(char** args, objectType operator) {
	double value = 0;
	double arg[2] = { atof(args[0]), atof(args[1]) };

	switch (operator) {
	case addition:
		value = arg[1] + arg[0];
		break;
	case subtraction:
		value = arg[1] - arg[0];
		break;
	case multiplication:
		value = arg[1] * arg[0];
		break;
	case division:
		value = arg[1] / arg[0];
		break;
	case power:
		value = pow(arg[1], arg[0]);
		break;
	case modulo:
		value = fmod(arg[1], arg[0]);
		break;
	case function:
		break;
	}

	return value;
}