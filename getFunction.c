#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <string.h>


/* Check if the string is the function name */
int getFunction(char* expression) {

	const char mathFunctions[10][4] = {
		"sin",
		"cos",
		"tg",
		"ctg",
		"log",
		"!",
		"p",
		"pi",
		"e",
		"g",
	};

	int expLength = strlen(expression);

	if (strcmp(mathFunctions[0], expression) == 0) {
		//it's a sin function
		return 0;
	}

	if (strcmp(mathFunctions[1], expression) == 0) {
		//it's a cos function
		return 1;
	}

	if (strcmp(mathFunctions[2], expression) == 0) {
		//it's a tg function
		return 2;
	}

	if (strcmp(mathFunctions[3], expression) == 0) {
		//it's a ctg function
		return 3;
	}

	if (strcmp(mathFunctions[4], expression) == 0) {
		//it's a log function
		return 4;
	}

	if (strcmp(mathFunctions[5], expression) == 0) {
		//it's a factiorial
		return 5;
	}

	if (strcmp(mathFunctions[6], expression) == 0
		|| strcmp(mathFunctions[7], expression) == 0) {
		//it's pi const 
		return 6;
	}

	if (strcmp(mathFunctions[8], expression) == 0) {
		//it's e const 
		return 7;
	}

	if (strcmp(mathFunctions[9], expression) == 0) {
		//it's pi const 
		return 8;
	}

	return -1;
}