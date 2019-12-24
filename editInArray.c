#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include "cstring.h"
#include <stdio.h>
#include <string.h>

/* Edit value in array */
char** editInArray(char** array, char* value, size_t* sizeOfArray, size_t index) {
	
	//If array is empty
	if (array == NULL || *sizeOfArray < 1) {
		//If sizeOfArray is wrong arg do not make memory leak of array
		if (array != NULL) {
			return array;
		}
		return 0;
	}

	//Given index is wrong
	if (index > *sizeOfArray) {
		return array;
	}

	//Pointer to value
	char* tmp = 0;
	tmp = appendToString(tmp,value);

	free(array[index]);

	array[index] = tmp;

	return array;
}