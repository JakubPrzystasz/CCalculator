#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* INSERT VALUE IN GIVEN INDEX (DO NOT REPLACE DATA) */
char** insertToArray(char** array, char* string, int* count, int index) {
	if (array == NULL) {
		return NULL;
	}

	if (index > *count || index < 0 || *count < 1) {
		return array;
	}

	int length = *count;

	//APPEND VALUE 
	if (index == *count) {
		array = appendToArray(array, string, &length);
		
		if (array == NULL) {
			return NULL;
		}
		
		*count = length;

		return array;
	}

	int tmpSize = *count + 1;
	char** tmpArray = malloc(tmpSize * sizeof(*array));
	
	if (tmpArray == NULL) {
		freeArray(array, length);
		return NULL;
	}

	//copy first part of array
	for (int i = 0;i < index;i++) {
		tmpArray[i] = array[i];
	}

	tmpArray[index] = (char*)malloc((strlen(string) + 1) * sizeof(char));

	if (tmpArray[index] == NULL) {
		freeArray(array, length);
		return NULL;
	}

	//append new value
	strcpy(tmpArray[index], string);

	//copy second part of array 
	for (int i = index;i < tmpSize;i++) {
		tmpArray[i+1] = array[i];
	}
	
	*count = tmpSize;

	return tmpArray;
}
