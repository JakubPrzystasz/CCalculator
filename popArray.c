#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* REMOVE LAST VALUE OF ARRAY */
char** popArray(char** array, int* count) {
	if (array == NULL || *count < 1) {
		return NULL;
	}

	char** tmpArray = array;
	char* tmpVal = array[*count - 1];
	free(array[(*count - 1)]);

	array = (char**)realloc(array, (*count - 1) * sizeof(*array));
	
	if(array == NULL){
		freeArray(tmpArray,*count);
		free(tmpVal);
		return NULL;
	}

	*count -= 1;

	return array;
}
