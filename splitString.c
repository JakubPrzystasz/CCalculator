#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "array.h"
#include <stdio.h>

char** splitString(char* string, const char delimiter, size_t* sizeOfArray) {
	//Output array
	char** array = 0;
	
	//Temporary string
	char* tmp = 0;

	//If value is null 
	if (string == NULL || strlen(string) < 1) {
		return NULL;
	}

	for (unsigned int i = 0; i < (strlen(string) - 1); i++) {

		//Current character
		char value[2] = { string[i],'\0' };

		//Append value if it's not a delimiter
		if (value[0] != delimiter) {
			tmp = appendToString(tmp, value);
			continue;
		}

		//Current character is a delimiter
		array = appendToArray(array, tmp, sizeOfArray);
		tmp = emptyString(tmp);
	}

	return array;
}