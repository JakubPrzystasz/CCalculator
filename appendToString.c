#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdlib.h>
#include <string.h>

/* Append value to string */
char* appendToString(char* string, char* value) {
	//If value is null 
	if (value == NULL || strlen(value) < 1) {
		return string;
	}

	char* tmpString = 0;

	//Initialize new string
	if (string == NULL) {
        string = (char*)malloc((strlen(value)+1)*sizeof(char));
		if (string == NULL) {
			return  NULL;
		}
		string = strcpy(string, value);
		return string;
	} else {
    //Append value to existing string
		tmpString = (char*)malloc((strlen((char*)string) + 1) * sizeof(char));
		if (tmpString == NULL) {
			return  NULL;
		}
		tmpString = strcpy(tmpString, string);
		tmpString = strcat(tmpString, value);

		if(tmpString == NULL){
			return NULL;
		}

		free(string);

		return tmpString;
	}
}
