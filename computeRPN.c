#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/* Compute value of RPN expression */
double computeRPN(char** expressionArray, int* length) {
	char** stack = 0;
	int stackSize = 0;
	char* arg1 = 0;
	char* arg2 = 0;

	double result = 0;

	/*
	    Dla wszystkich symboli z wyra�enia ONP wykonuj:
        je�li i-ty symbol jest liczb�, to od�� go na stos,
        je�li i-ty symbol jest operatorem to:
            zdejmij ze stosu jeden element (ozn. a),
            zdejmij ze stosu kolejny element (ozn. b),
            od�� na stos warto�� b operator a.
        je�li i-ty symbol jest funkcj� to:
            zdejmij ze stosu oczekiwan� liczb� parametr�w funkcji(ozn. a1...an)
            od�� na stos wynik funkcji dla parametr�w a1...an
    Zdejmij ze stosu wynik.
	*/
	
	for (int index = 0;index < *length;index++) {
		arg1 = 0;
		arg2 = 0;

		if (stackSize > 0) {
			arg1 = appendToString(arg1, stack[stackSize - 1]);
		}
		if (stackSize > 1) {
			arg2 = appendToString(arg2, stack[stackSize - 2]);
		}

		/*je�li i-ty symbol jest liczb�, to od�� go na stos*/
		if (getExpType(expressionArray[index]) == number) {
			stack = appendToArray(stack, expressionArray[index], &stackSize);
			continue;
		}

		/*je�li i-ty symbol jest operatorem to:
			zdejmij ze stosu jeden element (ozn. a),
			zdejmij ze stosu kolejny element (ozn. b),
			od�� na stos warto�� b operator a.*/
		if ((getExpType(expressionArray[index]) != number && getExpType(expressionArray[index]) != function
				&& getExpType(expressionArray[index]) != undefined) && stackSize > 1) {
			
			stack = popArray(stack, &stackSize, true);
			stack = popArray(stack, &stackSize, true);
			stack = appendToArray(stack, doMath(getExpType(expressionArray[index]), arg1, arg2), &stackSize);
		}

	}

	if (stack != NULL) {
		result = atof(stack[0]);
	}
	
	return  result;
}