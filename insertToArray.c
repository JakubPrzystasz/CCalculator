#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Insert new value to array */
char** insertToArray(char** array, char* value, size_t* sizeOfArray, size_t index) {
	
	//When array is empty append value
	if (array == NULL && *sizeOfArray == 0) {
		array = appendToArray(array, value, sizeOfArray);
		return array;
	}

	//Check length of array
	if (*sizeOfArray == 0 && array != NULL) {
		return array;
	}

	//When index is greater than size of array
	if (index > *sizeOfArray) {
		return array;
	}
	
	//If index points to last element of array 
	if (index == *sizeOfArray) {
		array = appendToArray(array, value, sizeOfArray);
		return array;
	}
	
	//Pointer to value
	char* tmp = 0;
	tmp = (char*)malloc((strlen((char*)value) + 1) * sizeof(char));

	//Unable to allocate memory
	if (tmp == NULL) {
		freeArray(array, sizeOfArray);
		return NULL;
	}

	strcpy(tmp, value);

	//Append value to existing array
	//Temporary pointer to array
	char** tmpArray = array;
	array = (char**)realloc(array, (*sizeOfArray + 1) * sizeof(*array));

	//Unable to allocate memory
	if (array == NULL) {
		freeArray(tmpArray, *sizeOfArray);
		return NULL;
	}
	
	//Move right side of array from index
	/*
	   0   1   2   3   4   5
	   A   B   C   D   E   Empty
				  /\ - index at 3
	   0   1   2   3   4   5
	   A   B   C Empty D   E   
	*/
	//Empty space will be filled with new value

	for (size_t i = (*sizeOfArray); i > index; i--) {
		array[i] = array[(i - 1)];
	}

	//Fill empty space with new value
	array[index] = tmp;
	
	*sizeOfArray += 1;

	return array;
}
