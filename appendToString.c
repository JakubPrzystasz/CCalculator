#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* APPEND VALUE TO STRING */
char* appendToString(char* string, char* value) {
	//INITIALIZE NEW STRING
	if (string == NULL) {
		int r = strlen(value);
        string = (char*)calloc(strlen(value)+1, sizeof(char));
		if (string == NULL) {
			return -1;
		}
		string = strcpy(string, value);
	} else {
    //APPEND VALUE TO EXISITING STRING
		char* tmpString = (char*) malloc((strlen((char*)string) + 2) * sizeof(char));
		if (tmpString == NULL) {
			return -1;
		}
		tmpString = strcpy(tmpString, string);
		tmpString = strcat(tmpString, value);

		if(tmpString == NULL){
            return -1;
		}

		free(string);
		string = tmpString;
	}
	return string;
}
