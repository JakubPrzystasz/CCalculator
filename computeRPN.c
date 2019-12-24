#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

/* Compute value of RPN expression */
double computeRPN(char** array, size_t* sizeOfArray) {
	
	char** stack = 0;
	size_t sizeOfStack = 0;

	char** args = 0;
	size_t sizeOfArgs = 0;
	
	char* string = 0;

	expType type = undefined;

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

		type = getExpType(array[index]);

		/*jeœli i-ty symbol jest liczb¹, to od³ó¿ go na stos*/
		if (type == number) {
			stack = appendToArray(stack, array[index], &sizeOfStack);
			continue;
		}

		/*
			jeœli i-ty symbol jest operatorem to:
			zdejmij ze stosu jeden element (ozn. a),
			zdejmij ze stosu kolejny element (ozn. b),
			od³ó¿ na stos wartoœæ b operator a
		*/
		if (isOperator(type) == true && sizeOfStack > 1) {
			args = appendToArray(args, stack[sizeOfStack - 1], &sizeOfArgs);
			args = appendToArray(args, stack[sizeOfStack - 2], &sizeOfArgs);
			stack = popArray(stack, &sizeOfStack, true);
			stack = popArray(stack, &sizeOfStack, true);
			
			string = emptyString(string);

			string = appendToString(string,basicCalculation(args, type));

			freeArray(args, &sizeOfArgs);

			stack = appendToArray(stack,string, &sizeOfStack);
		}

		/*
		jeœli i - ty symbol jest funkcj¹ to :
		zdejmij ze stosu oczekiwan¹ liczbê parametrów funkcji(ozn.a1...an)
			od³ó¿ na stos wynik funkcji dla parametrów a1...an
		*/
		if (type == function) {
			switch (getFunction(array[index])) {
			case 0:
				//log
				args = appendToArray(args, stack[sizeOfStack - 1], &sizeOfArgs);
				args = appendToArray(args, stack[sizeOfStack - 2], &sizeOfArgs);
				stack = popArray(stack, &sizeOfStack, true);
				stack = popArray(stack, &sizeOfStack, true);

				string = emptyString(string);

				string = appendToString(string, functionCalc(args, getFunction(array[index])));

				freeArray(args, &sizeOfArgs);

				stack = appendToArray(stack, string, &sizeOfStack);
				break;
			case 1:
				//e
				string = emptyString(string);
				string = appendToString(string, "2.71");
				stack = appendToArray(stack, string, &sizeOfStack);
				break;
			case 2:
				//e
				string = emptyString(string);
				string = appendToString(string, "3.14");
				stack = appendToArray(stack, string, &sizeOfStack);
				break;
			case 3: case 4: case 5:
				//factorial
				args = appendToArray(args, stack[sizeOfStack - 1], &sizeOfArgs);
				stack = popArray(stack, &sizeOfStack, true);

				string = emptyString(string);

				string = appendToString(string, functionCalc(args, getFunction(array[index])));

				freeArray(args, &sizeOfArgs);

				stack = appendToArray(stack, string, &sizeOfStack);
				break;
			};
		}
	}

	if (stack != NULL) {
		return atof(stack[0]);
	}
	
	return  0;
}