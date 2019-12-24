#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Delete value at index */
char** removeInArray(char** array, size_t* sizeOfArray, size_t index, bool deleteValue) {
	
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

	//When index points to the last value of array,
	//just pop last value
	if (index + 1 == *sizeOfArray) {
		array = popArray(array, sizeOfArray,deleteValue);
		return array;
	}

	//Append value to existing array
	//Temporary pointer to array
	char** tmpArray = array;
	array = (char**)realloc(array, (*sizeOfArray - 1) * sizeof(*array));

	//Unable to allocate memory
	if (array == NULL) {
		freeArray(tmpArray, *sizeOfArray);
		return NULL;
	}

	if (deleteValue == true) {
		free(tmpArray[index]);
	}

	/*
	   0   1   2   3   4   5
	   A   B   C   D   E   F
			       /\ - index at 3
	   0   1   2   3   4
	   A   B   C   E   F
	*/

	//The last value from old array goes to last element of new array
	array[*sizeOfArray - 2] = tmpArray[*sizeOfArray - 1];

	for (size_t i = (*sizeOfArray - 3); i > index; i--) {
		array[i] = tmpArray[(i+1)];
	}


	*sizeOfArray -= 1;

	return array;
}