#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "cstring.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Parse string to array of math expressions */
char** parseExpression(char* expression,size_t* sizeOfArray) {
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

	//Type of expression stored in string 
	expType expressionType = undefined;

	//When first character is '-' or '+' add 0 to output
	//this will prevent from future errors in calculations
	if (expression[0] == '-' || expression[0] == '+') {
		array = appendToArray(array, "0", sizeOfArray);
	}

	//Go through all string
	for (size_t i = 0; i < sizeOfExpression; i++) {
		//
		if (string == NULL || getType(string) != getType(expression[i])) {
			if (string != NULL) {
				array = appendToArray(array, string, sizeOfArray);
				string = emptyString(string);
			}
			string = appendToString(string,expression[i]);
			//
		} else {
			string = appendToString(string, expression[i]);
		}
	}

	//Add to array the last expression from string
	if (string != NULL) {
		array = appendToArray(array, string, sizeOfArray);
	}

	//dodawaj do stringa dopóki nie napotkasz czegos co nie jest cyfra
	//for (int i = 0; i < sizeOfExpression; i++) {
	//	char char1[2] = { expression[i],'\0' };
	//	if (i == 0 && char1[0] == '-') {
	//		array = appendToArray(array, "0", &count);
	//	}

	//	if (getOperator(char1) >= 0) {
	//		//natrafiono na operator
	//		if (string != 0) {
	//			array = appendToArray(array, string, &count);
	//			string = 0;
	//		}
	//		array = appendToArray(array, char1, &count);
	//	} else {
	//		if (string != 0) {
	//			if (!isNumber(char1) && expType == 0) {
	//				array = appendToArray(array, string, &count);
	//				string = 0;
	//				string = appendToString(string, char1);
	//				expType = 1;
	//			}
	//			else if (isNumber(char1) && expType == 1) {
	//				array = appendToArray(array, string, &count);
	//				string = 0;
	//				string = appendToString(string, char1);
	//				expType = 0;
	//			/* !!! */
	//			} else {
	//				string = appendToString(string, char1);
	//			}
	//		} else {
	//			string = appendToString(string, char1);
	//			if (isNumber(string)) {
	//				expType = 0;
	//			}
	//			else {
	//				expType = 1;
	//			}
	//		}
	//	}

	//	/* DEBUG */
	//	/*
	//	printf("STRING:%s | isNumber:%d | isDigit:%d | isFunc:%d | getOperator:%d | CHAR: %c \n",
	//	string,string!=0?isNumber(string):0,isDigit(char1),isFunction(char1),getOperator(   char1),char1);
	//	*/
	//	/* DEBUG */

	//}

	//for (int i = 0;i < count - 1;++i) {
	//	if (isNumber(array[i]) && getFunction(array[i + 1]) >= 0) {
	//		array = insertToArray(array, "*\0", &count, i + 1);
	//		i += 1;
	//		continue;
	//	}
	//	if (isNumber(array[i]) && getOperator(array[i + 1]) == 6) {
	//		array = insertToArray(array, "*\0", &count, i + 1);
	//		i += 1;
	//		continue;
	//	}
	//}

	return array;
}
