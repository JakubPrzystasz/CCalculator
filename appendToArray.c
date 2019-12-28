#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdlib.h>
#include <string.h>

/* Append value to array */
void** appendToArray(void** array, void* value, size_t* sizeOfArray, Type type) {

	//There is nothing to do 
	//!! Maybe throw error code? !!!
	if (value == NULL) {
		return array;
	}

	//Temporary pointer to array
	void** tmpArray = array;

	//Append value to array
	switch (type) {
	case tString:
		array = (char**)realloc(array, (*sizeOfArray + 1) * sizeof(char*));
		break;
	case tInt:
		array = (int**)realloc(array, (*sizeOfArray + 1) * sizeof(int*));
		break;
	case tDouble:
		array = (double**)realloc(array, (*sizeOfArray + 1) * sizeof(double*));
		break;
	};


	//Unable to allocate memory
	if (array == NULL) {
		//freeArray(tmpArray, *sizeOfArray,type);
		return NULL;
	}


	//Allocate memory for value
	switch (type) {
	case tString:
		array[*sizeOfArray] = (char*)malloc((strlen((char*)value) + 1) * sizeof(char));
		break;
	case tInt:
		array[*sizeOfArray] = (int*)malloc(sizeof(int));
		break;
	case tDouble:
		array[*sizeOfArray] = (double*)malloc(sizeof(double));
		break;
	};

	//Unable to allocate memory
	if (array[*sizeOfArray] == NULL) {
		//freeArray(array, *sizeOfArray);
		return NULL;
	}

	//Copy value to array
	switch (type) {
	case tString:
		strcpy(array[*sizeOfArray], value);
		break;
	case tInt:
		memcpy(array[*sizeOfArray], value, sizeof(int));
		break;
	case tDouble:
		memcpy(array[*sizeOfArray], value, sizeof(double));
		break;
	};

	*sizeOfArray += 1;

	return array;
}
