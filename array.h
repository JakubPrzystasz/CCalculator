#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdbool.h>

#ifndef ARRAY_H
#define ARRAY_H

	/* Array  */
	void freeArray(char** array, size_t size);
	void printArray(char** array, int* count);
	char** popArray(char** array, int* count, bool remove);
	char** appendToArray(char** array, char* string, int* count);
	char** insertToArray(char** array, char* string, int* count, int index);
	char** editInArray(char** array, char* string, int* count, int index);
	char** removeInArray(char** array, int* count, int index);

#endif