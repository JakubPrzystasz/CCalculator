#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdlib.h>
#include <string.h>

/* Pop last char of string */
char* popString(char* string) {
	
	//If string is null 
	if (string == NULL) {
		return string;
	}

	size_t sizeOfString = strlen(string);

	if (sizeOfString < 1) {
		return string;
	}
	
	if (strlen(string) == 1) {
		free(string);
		return NULL;
	}

	//Delete last value - in strings it's always termination \0
	free(string[sizeOfString]);

	//Replace value of last readable char to \0
	string[sizeOfString - 1] = '\0';

	return string;
}
