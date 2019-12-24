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
		//When allocation fails, prevent from copying data nowhere
		if (string == NULL) {
			return  NULL;
		}
		string = strcpy(string, value);
		return string;
	} else {
    //Append value to existing string
		//Allocate memory for bigger string
		tmpString = (char*)malloc((strlen((char*)string) + strlen((char*)value) + 1) * sizeof(char));
		
		//If allocation fails return old value
		if (tmpString == NULL) {
			return string;
		}
		
		//Copy old part of string
		tmpString = strcpy(tmpString, string);
		//Add new part
		tmpString = strcat(tmpString, value);

		//If something went wrong
		if(tmpString == NULL){
			return string;
		}

		//We dont need old string anymore
		free(string);

		return tmpString;
	}
}
