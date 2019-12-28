#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/* Compute value of RPN expression */
double calculatePostfix(char** array, size_t* sizeOfArray) {
	
	char** stack = 0;
	size_t sizeOfStack = 0;

	char* string = 0;

	objectType type = undefined;

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
	
	for (size_t index = 0;index < *sizeOfArray;index++) {

		type = getObjectType(array[index]);

		/*je�li i-ty symbol jest liczb�, to od�� go na stos*/
		if (type == number) {
			stack = appendToArray(stack, array[index], &sizeOfStack, tString);
			continue;
		}

		/*
			je�li i-ty symbol jest operatorem to:
			zdejmij ze stosu jeden element (ozn. a),
			zdejmij ze stosu kolejny element (ozn. b),
			od�� na stos warto�� b operator a
		*/
		if (isOperator(type) && sizeOfStack > 1) {
			stack = calculateValue(stack, &sizeOfStack, type);
		}

		/*
		je�li i - ty symbol jest funkcj� to :
		zdejmij ze stosu oczekiwan� liczb� parametr�w funkcji(ozn.a1...an)
			od�� na stos wynik funkcji dla parametr�w a1...an
		*/
		if (isFunction(type) && sizeOfStack > 1) {
			stack = calculateValue(stack, &sizeOfStack, type);
		}
	}

	if (stack != NULL) {
		return atof(stack[0]);
	}
	
	return  0;
}