#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/* Compute value of RPN expression */
double calculatePostfix(char** array, size_t* sizeOfArray) {
	
	//Stack of operands
	double** stack = 0;
	//Size of stack
	size_t sizeOfStack = 0;

	//Type of object in array
	objectType type = undefined;

	//Temporary value of operand
	double tmp = 0;

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

		tmp = atof(array[index]);

		/*jeœli i-ty symbol jest liczb¹, to od³ó¿ go na stos*/
		if (type == number) {
			stack = appendToArray(stack, &tmp, &sizeOfStack, tDouble);
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
		if (isFunction(type)) {
			stack = calculateValue(stack, &sizeOfStack, type);
		}
	}

	if (stack != NULL && sizeOfStack == 1) {
		return *stack[0];
	}
	
	return  0;
}