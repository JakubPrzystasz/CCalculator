#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* REMOVE VALUE AT GIVEN INDEX */
char** removeInArray(char** array, int* count, int index) {
	if (array == NULL) {
		return NULL;
	}

	if (index > *count || index < 0 || *count < 1) {
		return array;
	}

	int length = *count;

	//pop value 
	if (index + 1 == *count) {
		array = popArray(array, &length,true);

		if (array == NULL) {
			return NULL;
		}

		*count = length;

		return array;
	}

	int tmpSize = *count - 1;
	char** tmpArray = malloc(tmpSize * sizeof(*array));

	if (tmpArray == NULL) {
		freeArray(array, length);
		return NULL;
	}

	//copy first part of array
	for (int i = 0;i < index;i++) {
		tmpArray[i] = array[i];
	}
	
	//copy second part of array 
	for (int i = index;i < length-(index);i++) {
		tmpArray[i] = array[i + 1];
	}

	free(array[index]);

	*count = tmpSize;

	return tmpArray;
}