#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
#include <math.h>

double addition(char* args) {

	size_t sizeOfArray = 0;

	//Args in array
	char** argsString = splitString(args,',',&sizeOfArray);

	if (sizeOfArray == 2) {
		double arg[2] = { atof(argsString[0]),atof(argsString[1]) };
		return arg[0] + arg[1];
	}

	return -1;
}