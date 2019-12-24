#define _CRT_SECURE_NO_WARNINGS
#include "array.h"
#include <stdlib.h>
#include <string.h>

/* Append value to array */
char** appendToArray(char** array, char* value,size_t* sizeOfArray) {

	//There is nothing to do 
	//!! Maybe throw error code? !!!
	if (value == NULL){
		return array;
	}	

    //Initialize new array if pointer is null
    if (array == NULL){
        array = (char**) malloc(sizeof(*array));
		
		//Unable to allocate memory
        if(array == NULL){
			return NULL;
        }

		//Allocate memory for value
		//Pointer always points to the first element,
		//cause of that I dont have to use array[0]
        array = (char*)malloc((strlen((char*)value)+1) * sizeof(char));
		
		//Unable to allocate memory
		if(array == NULL){
			return NULL;
        }
    }

    //Append value to existing array
	//Temporary pointer to array
    char** tmpArray = array;
	array = (char**) realloc(array, (*sizeOfArray + 1) * sizeof(*array));
	
	//Unable to allocate memory
	if(array == NULL){
		freeArray(tmpArray,*sizeOfArray);
		return NULL;
	}

	//Allocate memory for value
    array[*sizeOfArray] = (char*)malloc((strlen((char*)value)+1) * sizeof(char));
    
	//Unable to allocate memory
	if (array[*sizeOfArray] == NULL){
		freeArray(array,*sizeOfArray);
		return NULL;
    }

	//Copy value to array
    strcpy(array[*sizeOfArray],value);

	*sizeOfArray += 1;

	return array;
}
