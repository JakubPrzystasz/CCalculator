#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "cstring.h"
#include "array.h"
#include <stdio.h>
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

	//Types of tokens
	expType charType = undefined;
	expType stringType = undefined;

	//When first character is '-' or '+' add 0 to output
	//this will prevent from future errors in calculations
	if (expression[0] == '-' || expression[0] == '+') {
		array = appendToArray(array, "0", sizeOfArray);
	}

	//Go through all string
	for (size_t i = 0; i < sizeOfExpression; i++) {

		//Current character
		char exp[2] = { expression[i],'\0' };
		
		//Type stored in char
		charType = getExpType(&exp);

		//Break when occured undefined character
		if (charType == undefined) {
			break;
		}

		//Type in string
		stringType = getExpType(string);

		if (string == NULL) {
			string = appendToString(string, &exp);
			continue;
		}

		//When expressions type is different
		if (stringType != charType) {
			array = appendToArray(array, string, sizeOfArray);

			//when we need to add * betwen 
			if (stringType == number && (charType == function || charType == leftBracket)) {
				array = appendToArray(array, "*\0", sizeOfArray);
			}

			string = emptyString(string);
			string = appendToString(string, &exp);
			continue;
		}

		if (stringType == charType) {
			//Split two operators eg. ))
			if (getExpType(string) != number && getExpType(string) != function) {
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

	////Expression is splitted in array, now we must 
	////make functions and their agrs be in one place
	////and check if there is some of undefined functions

	//for (size_t i = 0; i < *sizeOfArray - 1; i++) {
	//	if (getExpType(array[i]) == function) {
	//		if (getFunction(array[i]) < 0) {
	//			//Occured undefined function
	//			printf("SYNTRAX ERROR\n");
	//			break;
	//		} else {
	//			//No args
	//			// 1 - e 2 - pi

	//			//One arg
	//			//  > 2
	//			
	//			//Two args
	//			// == 0 log
	//		}
	//	}
	//}

	return array;
}
