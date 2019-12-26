#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

/* Convert integer to readable string */
char* intToString(uint64_t value) {
	
	//Sign of value
	bool valSign = value >= 0 ? true : false;

	//String
	char* string = 0;

	if (value == 0 || value == NULL) {
		string = appendToString(string, "0");
		return string;
	}

	//Absolute value of value
	if (!valSign) {
		value *= -1;
	}

	while (true) {
		//Temporary char
		char tmp[2] = { 48 + (value % 10), '\0' };
		string = appendToString(string,&tmp);
		value =  value / 10;
		if (value == 0) { break; }
	}

	reverseString(string);

	return string;

}
