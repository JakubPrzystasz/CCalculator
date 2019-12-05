#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>

/* Just print array */
void printArray(char** array, int* count) {

	for (int i = 0;i < *count;i++) {
		printf("[%d]->{%s}\n", i, array[i]);
	}

}
