#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>
#include <string.h>

/* EDIT VALUE IN ARRAY */
char** editInArray(char** array, char* string, int* count, int index) {
	if (array == NULL) {
		return NULL;
	}

	if (index > *count || index < 0 || *count < 1) {
		return array;
	}

	int length = *count;

	char* tmp = (char*) malloc((strlen((char*)string) + 1) * sizeof(char));
	if (tmp == NULL) {
		freeArray(array,length);
		return NULL;
	}

	strcpy(tmp, string);
	free(array[index]);
	array[index] = tmp;
	
	return array;
}