#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* REMOVE VALUE AT GIVEN INDEX */
char** removeInArray(char** array, int* count, int index) {
	if (index >= *count || index < 0 || array == NULL) {
		return 1;
	}

	//just pop value
	int length = *count;
	if (index + 1 == length) {
		if (popArray(array, &length) != 0) {
			return 1;
		}

		*count = length;
	}

	free(array[index]);

	char** tempArray = 0;
	int countTemp = 0;
	for (int i = 0;i < length;i++) {
		if (i == index) {
			continue;
		}
		if (appendToArray(tempArray, array[i], &countTemp) != 0) {
			return 1;
		}
	}
	
	array = tempArray;

	return 0;
}