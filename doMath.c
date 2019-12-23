#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char* doMath(int operator,char* arg1, char* arg2) {
	double value = 0;
	char* result = 0;
	result = appendToString(result, "");
	double ARG1 = atof(arg1);
	double ARG2 = atof(arg2);

	switch (operator) {
	case 0:
		value = ARG2 + ARG1;
		break;
	case 1:
		value = ARG2 - ARG1;
		break;
	case 2:
		value = ARG2 * ARG1;
		break;
	case 3:
		value = ARG2 / ARG1;
		break;
	case 4:
		value = pow(ARG2, ARG1);
		break;
	case 5:
		value = fmod(ARG2, ARG1);
		break;
	}
	sprintf(result, "%lf", value);
	return result;
}