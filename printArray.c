#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>

/* Print array to std out*/
void printArray(char** array, size_t* sizeOfArray) {
	
	//If array is empty
	if (*sizeOfArray < 1 || array == NULL) {
		printf("Array is empty\n");
		return;
	}

	//Print each value in format: [index]->{value}
	for (size_t i = 0;i < *sizeOfArray;i++) {
		printf("[%zu]->{%s}\n", i, array[i]);
	}

}
