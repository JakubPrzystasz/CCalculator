#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>

#ifndef CSTRING_H
#define CSTRING_H

	/* String */
	
	bool isDigit(char expression);
	bool isNumber(char* expression);
	char* appendToString(char* string, char* value);
	char* emptyString(char* string);

#endif