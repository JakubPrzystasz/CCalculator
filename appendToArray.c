#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* APPEND STRING TO END OF ARRAY */
char** appendToArray(char** array, char* string,int* count) {
    if (string == NULL){
        return 1;
    }

    //initialize new array
    if (array == NULL){
        array = (char **) malloc(sizeof(*array));
        if(array == NULL){
            return 1;
        }
        array[0] = (char *)malloc((strlen((char*)string)+1)*sizeof(char));
        if(array[0] == NULL){
            return 1;
        }
    }

    //append vale in existing array
    char** tmpArray = array;
	array = (char **) realloc(array, (*count + 1) * sizeof(*array));
	if(array == NULL){
		array = tmpArray;
        return 1;
	}
    array[*count] = (char *)malloc((strlen((char*)string)+1)*sizeof(char));
    if (array == NULL){
        return 1;
    }

    strcpy(array[*count],string);
    *count = *count + 1;
    return 0;
}
