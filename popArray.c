#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* USUÑ OSTANIA WARTOŒÆ */
int popArray(char** array, int* count) {
	if (*count < 1 || array == NULL) {
		exit(1);
	}
	free(array[*count - 1]);
	array = (char**)realloc(array, (*count - 1) * sizeof(*array));
	*count -= 1;
	return array;
}