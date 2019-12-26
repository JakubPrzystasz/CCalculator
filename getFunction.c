#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <string.h>


/* Check if the string is a function name */
byte getFunction(char* expression) {

	const char mathFunctions[8][3] = {
		"log",
		"e",
		"pi",
		"!",
		"sin",
		"cos",
		"tg",
		"ctg",
	};

	int expLength = strlen(expression);

	if (strcmp(mathFunctions[0], expression) == 0) {
		//it's log
		return 0;
	}

	if (strcmp(mathFunctions[1], expression) == 0) {
		//it's e
		return 1;
	}

	if (strcmp(mathFunctions[2], expression) == 0) {
		//it's pi
		return 2;
	}

	if (strcmp(mathFunctions[3], expression) == 0) {
		//it's factorial
		return 3;
	}

	if (strcmp(mathFunctions[4], expression) == 0) {
		//it's sin
		return 4;
	}

	if (strcmp(mathFunctions[5], expression) == 0) {
		//it's cos
		return 5;
	}

	if (strcmp(mathFunctions[6], expression) == 0) {
		//it's tg
		return 6;
	}

	if (strcmp(mathFunctions[7], expression) == 0) {
		//it's ctg
		return 7;
	}

	return -1;
}