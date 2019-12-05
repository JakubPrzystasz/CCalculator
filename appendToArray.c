#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* APPEND STRING TO END OF ARRAY */
char** appendToArray(char** array, char* string,int* count) {
    if (string == NULL){
		freeArray(array, *count);
		return NULL;
	}	

    //initialize new array
    if (array == NULL){
        array = (char **) malloc(sizeof(*array));
        if(array == NULL){
			return NULL;
        }
        array[0] = (char *)malloc((strlen((char*)string)+1)*sizeof(char));
        if(array[0] == NULL){
			free(array);
			return NULL;
        }
    }

    //append value in existing array
    char** tmpArray = array;
	array = (char **) realloc(array, (*count + 1) * sizeof(*array));
	if(array == NULL){
		freeArray(tmpArray,*count);
		return NULL;
	}

    array[*count] = (char *)malloc((strlen((char*)string)+1)*sizeof(char));
    
	if (array[*count] == NULL){
		freeArray(array,*count);
		return NULL;
    }

    strcpy(array[*count],string);

	*count += 1;

	return array;
}
