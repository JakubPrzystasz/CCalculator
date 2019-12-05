#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* INSERT VALUE IN GIVEN INDEX (DO NOT REPLACE DATA) */
char** insertToArray(char** array, char* string, int* count, int index) {
	if (index > *count || index < 0 || *count < 1) {
		return 1;
	}

	int length = *count;

	//APPEND VALUE 
	if (index == *count) {
		if (appendToArray(array, string, &length) != 0) {
			return 1;
		}
		*count = length;
		return 0;
	}

	char** tmpArray = array;
	array = realloc(array,(*count + 1) * sizeof(*array));
	if (array == NULL) {
		array = tmpArray;
		return 1;
	}
	
	array = tmpArray;

	tmpArray = 0;
	int countTemp = 0;

	//ADD VALUE AND TAIL OF GIVEN ARRAY
	if (appendToArray(tmpArray, string, &countTemp != 0)) {
		return 1;
	}

	for (int i = 0;i < (*count - index);i++) {
		if (appendToArray(tmpArray, array[index + i], &countTemp) != 0) {
			return 1;
		}
	}
	
	//MERGE TWO ARRAYS
	for (int i = 0;i < (*count - index);i++) {
		if (editInArray(array, tmpArray[i], &length, i + index) != 0) {
			return 1;
		}
	}

	//ADD LAST VALUE
	if (appendToArray(array, tmpArray[*count - index], &length) != 0) {
		return 1;
	}

	*count = length;
	return 0;
}
