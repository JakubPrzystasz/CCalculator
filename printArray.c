#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>

/* Just print array */
void printArray(char** array, int* count) {
	if (*count < 1) {
		return;
	}

	for (int i = 0;i < *count;i++) {
		printf("[%d]->{%s}\n", i, array[i]);
	}

}
