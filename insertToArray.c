#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DOPISZ DO TABICY WARTOSC WE WSKAZANYM MIEJSCU */
int insertToArray(char** array, char* string, int* count, int index) {
	if (index > * count || index < 0) {
		exit(1);
	}

	int length = *count;
	if (index < 0) { exit(1); }
	if (index == length) {
		array = appendToArray(array, string, &length);
		*count = length;
		return array;
	}

	array = (char**)realloc(array, (length + 1) * sizeof(*array));
	if (array == NULL) {
		exit(1);
	}

	char** tempArray = 0;
	int countTemp = 0;
	tempArray = appendToArray(tempArray, string, &countTemp);
	for (int i = 0;i < (length - index);i++) {
		tempArray = appendToArray(tempArray, array[index + i], &countTemp);
	}

	for (int i = 0;i < (length - index);i++) {
		array = editInArray(array, tempArray[i], &length, i + index);
	}
	array = appendToArray(array, tempArray[length - index], &length);
	*count = length;
	return array;
}