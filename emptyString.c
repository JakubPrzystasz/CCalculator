#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdlib.h>
#include <string.h>

/* Make string empty */
char* emptyString(char* string) {
	//If value is null 
	if (string == NULL) {
		return string;
	}

	free(string);

	return NULL;
}
