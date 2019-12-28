#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "cstring.h"
#include "array.h"
#include <stdlib.h>
#include <string.h>

/* Parse string to array of math expressions */
char** parseString(char* expression, size_t* sizeOfArray) {
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

	//Type of char
	objectType charType = undefined;
	
	//Type of string 
	objectType stringType = undefined;

	//When first character is '-' or '+' add 0 to output
	//this will prevent from future errors in calculations
	if (expression[0] == '-' || expression[0] == '+') {
		array = appendToArray(array, "0", sizeOfArray, tString);
	}

	//Go through all string
	for (size_t i = 0; i < sizeOfExpression; i++) {

		//Current character
		char exp[2] = { expression[i],'\0' };
		
		//Type stored in char
		charType = getObjectType(&exp);

		//Type in string
		stringType = getObjectType(string);

		if (string == NULL) {
			string = appendToString(string, &exp);
			continue;
		}

		//When expressions type is different
		if (stringType != charType) {
			array = appendToArray(array, string, sizeOfArray, tString);

			//when we need to add * betwen 
			if (stringType == number && (isFunction(charType) || charType == leftBracket)) {
				array = appendToArray(array, "*\0", sizeOfArray, tString);
			}

			string = emptyString(string);
			string = appendToString(string, &exp);
			continue;
		}

		if (stringType == charType) {
			//Split two operators eg. ))
			if (getObjectType(string) != number && !isFunction(getObjectType(string))) {
				array = appendToArray(array, string, sizeOfArray, tString);
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
		array = appendToArray(array, string, sizeOfArray, tString);
	}

	return array;
}
