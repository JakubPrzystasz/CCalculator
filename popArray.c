#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* REMOVE LAST VALUE OF ARRAY */
char** popArray(char** array, int* count,bool removeValue) {
	if (array == NULL){
		return 0;
	}

	if (*count < 1) {
		return array;
	}

	if (*count == 1) {
		if (removeValue == 1) {
			free(array[0]);
		}
		free(array);
		*count = 0;
		return 0;
	}

	char** tmpArray = array;
	char* tmpVal = array[*count - 1];

	if (removeValue == 1) {
		free(array[(*count - 1)]);
	}

	array = (char**)realloc(array, (*count - 1) * sizeof(*array));
	
	if(array == NULL){
		freeArray(tmpArray, *count);
		free(tmpVal);
		return 0;
	}

	*count -= 1;

	return array;
}
