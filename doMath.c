#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char* doMath(expType operator,char* arg1, char* arg2) {
	double value = 0;
	char* result = 0;
	result = appendToString(result, "");
	double ARG1 = atof(arg1);
	double ARG2 = atof(arg2);

	switch (operator) {
	case addition:
		value = ARG2 + ARG1;
		break;
	case subtraction:
		value = ARG2 - ARG1;
		break;
	case multiplication:
		value = ARG2 * ARG1;
		break;
	case division:
		value = ARG2 / ARG1;
		break;
	case power:
		value = pow(ARG2, ARG1);
		break;
	case modulo:
		value = fmod(ARG2, ARG1);
		break;
	}
	sprintf(result, "%lf", value);
	return result;
}