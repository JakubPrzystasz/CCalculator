#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdbool.h>

#ifndef ARRAY_H
#define ARRAY_H

	/* Array  */

	void freeArray(char** array, size_t* sizeOfArray);
	void printArray(char** array, size_t* sizeOfArray);
	char** popArray(char** array, size_t* sizeOfArray, bool deleteValue);
	char** removeInArray(char** array, size_t* sizeOfArray, size_t index,bool deleteValue);
	char** appendToArray(char** array, char* value, size_t* sizeOfArray);
	char** insertToArray(char** array, char* value, size_t* sizeOfArray, size_t index);
	char** editInArray(char** array, char* value, size_t* sizeOfArray, size_t index);

#endif