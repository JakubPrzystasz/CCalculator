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
	objectType typeOfChar = undefined;
	
	//Type of string 
	objectType typeOfString = undefined;

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
		typeOfChar = getObjectType(&exp);

		//Type in string
		typeOfString = getObjectType(string);

		if (string == NULL) {
			string = appendToString(string, &exp);
			continue;
		}

		/*if (isFunction(typeOfString) && typeOfChar != leftBracket) {

			array = appendToArray(array, string, sizeOfArray, tString);
			string = emptyString(string);
			
			string = appendToString(string, "(");
			array = appendToArray(array, string, sizeOfArray, tString);
			string = emptyString(string);
			
			for (i; i < sizeOfExpression; i++) {
				exp[0] = expression[i];
				typeOfChar = getObjectType(&exp);
				if (!isOperator(typeOfChar)) {
					string = appendToString(string, &exp);
				} else {
					array = appendToArray(array, string, sizeOfArray, tString);
					string = emptyString(string);

					string = appendToString(string, ")");
					array = appendToArray(array, string, sizeOfArray, tString);
					string = emptyString(string);
					break;
				}
			}
			if (i == sizeOfExpression) {
				array = appendToArray(array, string, sizeOfArray, tString);
				string = emptyString(string);

				string = appendToString(string, ")");
				array = appendToArray(array, string, sizeOfArray, tString);
				string = emptyString(string);
			}
			continue;
		}*/

		//When expressions type is different
		if (typeOfChar != typeOfString) {
			array = appendToArray(array, string, sizeOfArray, tString);

			//when we need to add * betwen 
			if (typeOfString == number && (isFunction(typeOfChar) || typeOfChar == leftBracket)) {
				array = appendToArray(array, "*\0", sizeOfArray, tString);
			}

			// 5+(-4) =>> 5+(0-4)
			if (typeOfString == leftBracket && typeOfChar == subtraction) {
				array = appendToArray(array, "0\0", sizeOfArray, tString);
			}

			string = emptyString(string);
			string = appendToString(string, &exp);
			continue;
		}

		if (typeOfString == typeOfChar) {
			//Split two brackets
			if (typeOfChar == leftBracket || typeOfChar == rightBracket) {
				array = appendToArray(array, string, sizeOfArray, tString);
				string = emptyString(string);
			}
			string = appendToString(string, &exp);
			continue;
		}

	}

	//Add to array value of string
	if (string != NULL) {
		array = appendToArray(array, string, sizeOfArray, tString);
	}

	return array;
}
