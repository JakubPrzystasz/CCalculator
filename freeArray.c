#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdlib.h>

/* Delete array */
void freeArray(char** array, size_t* sizeOfArray)
{
	//If array is not null
	if (array != NULL && *sizeOfArray != NULL) {
		//Delete each of value
		for (size_t i = 0; i < *sizeOfArray; i++) {
			if (array[i] != NULL) {
				free(array[i]);
			}
		}
	}

}
