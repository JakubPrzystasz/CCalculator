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
	    Dla wszystkich symboli z wyra¿enia ONP wykonuj:
        jeœli i-ty symbol jest liczb¹, to od³ó¿ go na stos,
        jeœli i-ty symbol jest operatorem to:
            zdejmij ze stosu jeden element (ozn. a),
            zdejmij ze stosu kolejny element (ozn. b),
            od³ó¿ na stos wartoœæ b operator a.
        jeœli i-ty symbol jest funkcj¹ to:
            zdejmij ze stosu oczekiwan¹ liczbê parametrów funkcji(ozn. a1...an)
            od³ó¿ na stos wynik funkcji dla parametrów a1...an
    Zdejmij ze stosu wynik.
	*/
	
	for (size_t index = 0;index < *sizeOfArray;index++) {

		type = getObjectType(array[index]);

		/*jeœli i-ty symbol jest liczb¹, to od³ó¿ go na stos*/
		if (type == number) {
			stack = appendToArray(stack, array[index], &sizeOfStack, tString);
			continue;
		}

		/*
			jeœli i-ty symbol jest operatorem to:
			zdejmij ze stosu jeden element (ozn. a),
			zdejmij ze stosu kolejny element (ozn. b),
			od³ó¿ na stos wartoœæ b operator a
		*/
		if (isOperator(type) && sizeOfStack > 1) {
			stack = calculateValue(stack, &sizeOfStack, type);
		}

		/*
		jeœli i - ty symbol jest funkcj¹ to :
		zdejmij ze stosu oczekiwan¹ liczbê parametrów funkcji(ozn.a1...an)
			od³ó¿ na stos wynik funkcji dla parametrów a1...an
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