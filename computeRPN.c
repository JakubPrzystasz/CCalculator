#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Compute value of RPN expression */
double computeRPN(char** expressionArray, int* length) {
	char** stack = 0;
	int stackSize = 0;
	char* arg1 = 0;
	char* arg2 = 0;
	char* value = 0;
	char* tmp = 0;

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

		if (expressionArray[index] != NULL) {
			value = expressionArray[index];
		} else {
			return 0;
		}

		if (stackSize > 0) {
			if (arg1 != NULL) {
				free(arg1);
			}
			arg1 = appendToString(arg1, stack[stackSize - 1]);
		}
		if (stackSize > 1) {
			if (arg2 != NULL) {
				free(arg2);
			}
			arg2 = appendToString(arg2, stack[stackSize - 2]);
		}

		/*je�li i-ty symbol jest liczb�, to od�� go na stos*/
		if (isNumber(value) == 1) {
			stack = appendToArray(stack, value, &stackSize);
			continue;
		}

		/*je�li i-ty symbol jest operatorem to:
			zdejmij ze stosu jeden element (ozn. a),
			zdejmij ze stosu kolejny element (ozn. b),
			od�� na stos warto�� b operator a.*/
		if (getOperator(value) >= 0 && 5 >= getOperator(value)) {
			if (stackSize < 2) {
				return 0;
			}
			stack = popArray(stack, &stackSize,true);
			stack = popArray(stack, &stackSize,true);
			tmp = doMath(getOperator(value), arg1, arg2);
			stack = appendToArray(stack, tmp , &stackSize);
		}

	}

	if (stack != NULL) {
		result = atof(stack[0]);
	}
	
	return  result;
}