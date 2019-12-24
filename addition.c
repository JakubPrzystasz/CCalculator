#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
#include <math.h>

char* _addition(char** args) {

	char* string = 0;

	string = appendToString(string, "");
	
	double arg[2] = { atof(args[0]),atof(args[1]) };

	double tmp = arg[1] + arg[0];

	sprintf(string, "%lf", tmp);
	
	return string;

}