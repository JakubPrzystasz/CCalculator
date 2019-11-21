#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <string.h>

/* EDYTUJ WARTOSC W TABLICY */
int editArray(char** array, char* string, int* count, int index) {
	if (index >= *count || index < 0) {
		exit(1);
	}

	array[index] = (char*)realloc(array[index], (strlen((char*)string) + 1) * sizeof(char));
	if (array[index] == 0)
		exit(1);
	strcpy(array[index], string);
	return array;
}