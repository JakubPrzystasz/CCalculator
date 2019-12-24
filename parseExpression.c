#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "cstring.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Parse string to array of math expressions */
char** parseExpression(char* expression, size_t* sizeOfArray) {
	/*
		IMPORTANT!
		dot "." is a floating point
		comma "," is a delimited of function args
		sin(5) is equal to sin5, sin(3*3),sin5/2
		sin5+3 is equal to sin(5) + 3,
		if we want sin of 5+3: sin(5+3)

		all constants and variables are defined
		like functions, technically each are functions
		but some of them does not require any parameters
		to be passed, if we have function we need to
		calculate a value of each parameter, which can be
		a internal math expression, that means
		we have to parse each expression recursively
	*/

	//Get length of expression
	size_t sizeOfExpression = strlen(expression);

	//Initialize new array of strings
	char** array = 0;

	//Store a part of math expression - temporary
	char* string = 0;

	//When first character is '-' or '+' add 0 to output
	//this will prevent from future errors in calculations
	if (expression[0] == '-' || expression[0] == '+') {
		array = appendToArray(array, "0", sizeOfArray);
	}

	//Go through all string
	for (size_t i = 0; i < sizeOfExpression; i++) {
		
		char exp[2] = { expression[i],'\0' };
		
		if (string == NULL) {
			string = appendToString(string, &exp);
			continue;
		}

		if (getExpType(string) != getExpType(&exp)) {
			array = appendToArray(array, string, sizeOfArray);
			string = emptyString(string);
			string = appendToString(string, &exp);
			continue;
		}

		if (getExpType(string) == getExpType(&exp)) {
			//Split two operators eg. ))
			if (getExpType(string) != number && getExpType(string) != function
				&& getExpType(string) != undefined) {
				array = appendToArray(array, string, sizeOfArray);
				string = emptyString(string);
				string = appendToString(string, &exp);
				continue;
			}
			string = appendToString(string, &exp);
			continue;
		}

	}

	//Add to array the last expression from string
	if (string != NULL) {
		array = appendToArray(array, string, sizeOfArray);
	}

	for (size_t i = 0;i < *sizeOfArray - 1;++i) {
		if (getExpType(array[i]) == number && getExpType(array[i + 1]) == function) {
			array = insertToArray(array, "*\0", sizeOfArray, i + 1);
			i += 1;
			continue;
		}
		if (getExpType(array[i]) == number && getExpType(array[i + 1]) == leftBracket) {
			array = insertToArray(array, "*\0", sizeOfArray, i + 1);
			i += 1;
			continue;
		}
	}

	return array;
}
