#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>

/* REMOVE ARRAY FROM MEMORY */
void freeArray(char** array, size_t size)
{
	if (array != NULL) {
		for (int i = 0; i < size; i++)
			free(array[i]);
		free(array);
	}
	return 0;
}
