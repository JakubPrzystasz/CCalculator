#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* USUN WARTOSC WE WSKAZANYM INDEKSIE */
int removeInArray(char** array, int* count, int index) {
	if (index >= *count || index < 0 || array == NULL) {
		exit(1);
	}
	int length = *count;
	if (index + 1 == length) {
		array = popArray(array, &length);
		*count = length;
		return array;
	}

	free(array[index]);

	char** tempArray = 0;
	int countTemp = 0;
	for (int i = 1;i < (length - index);i++) {
		tempArray = appendToArray(tempArray, array[index + i], &countTemp);
	}

	array = (char**)realloc(array, (length - 1) * sizeof(*array));

	for (int i = 0;i + 1 < (length - index);i++) {
		array = editInArray(array, tempArray[i], &length, i + index);
	}

	*count = length - 1;
	return array;
}