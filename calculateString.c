#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <string.h>

/* Calculate value of string */
double calculateString(char* string) {
	
	//Initialize empty array of strings to store parsed expression
	char** expressionArray = 0;
	
	//Size of expression array 
	size_t sizeOfExpression = 0;

	//Initialize empty array of strings to store an RPN
	char** rpnArray = 0;

	//Size of rpn array 
	size_t sizeOfRpn = 0;

	/*DEBUG*/printf("Expression: {%s}\n", string);/*DEBUG*/
	/*DEBUG*/printf("Expression array:\n");/*DEBUG*/
	expressionArray = parseString(string, &sizeOfExpression);
	/*DEBUG*/printArray(expressionArray,&sizeOfExpression);/*DEBUG*/

	/*DEBUG*/printf("\nRNP array:\n");/*DEBUG*/
	rpnArray = toPostfix(expressionArray, &sizeOfExpression);
	/*DEBUG*/printArray(rpnArray, &sizeOfExpression);/*DEBUG*/

	return calculatePostfix(rpnArray,&sizeOfExpression);
}