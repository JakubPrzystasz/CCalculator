#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <string.h>


/* Check if the string is a function name */
byte getFunction(char* string) {

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

	int expLength = strlen(string);
	return 1;
}