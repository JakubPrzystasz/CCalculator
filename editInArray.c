#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <string.h>

/* EDIT VALUE IN ARRAY */
char** editInArray(char** array, char* string, int* count, int index) {
	if (index >= *count || index < 0) {
		return 1;
	}

	char* tmp = (char*) malloc((strlen((char*)string) + 1) * sizeof(char));
	if (tmp == NULL) {
		return 1;
	}
	strcpy(tmp, string);
	free(array[index]);
	array[index] = tmp;
	
	return 0;
}