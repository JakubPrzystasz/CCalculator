#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main()
{
	char* str = 0;
	str = appendToString(str, "Hello");
	str = appendToString(str, "World!");
	int arraySize = 0;
	char** array = 0;
	array = appendToArray(array, str, &arraySize);
	array = appendToArray(array, "FOO", &arraySize);
	array = appendToArray(array, "BAR", &arraySize);
	array = appendToArray(array, "RAR", &arraySize);

	printf("Before insertion at 1\n");
	printArray(array, &arraySize);
	array = insertToArray(array, "INSERTED", &arraySize, 1);

	printf("After insertion at 1, before remove at 1\n");
	printArray(array, &arraySize);
	array = removeInArray(array, &arraySize, 1);

	printf("After remove at 1, before edit at 1\n");
	printArray(array, &arraySize);
	array = editInArray(array, "EDITED", &arraySize, 1);

	printf("After edit at 1\n");
	printArray(array, &arraySize);

	return 0;
}
