#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double** calculateValue(double** array,size_t* sizeOfArray, objectType operator) {
	
	//Calculate value of operand
	if (isOperator(operator)) {
		
		double operand[2] = { *array[*sizeOfArray - 2],*array[*sizeOfArray - 1] };
		
		double value = 0;

		array = popArray(array, sizeOfArray, true, tDouble);
		array = popArray(array, sizeOfArray, true, tDouble);


		switch (operator) {
		case addition:
			value = operand[0] + operand[1];
			break;
		case subtraction:
			value = operand[0] - operand[1];
			break;
		case multiplication:
			value = operand[0] * operand[1];
			break;
		case division:
			if (operand[1] == 0) {
				value = 0;
				break;
			}
			value = operand[0] / operand[1];
			break;
		case power:
			value = pow(operand[0], operand[1]);
			break;
		case modulo:
			value = fmod(operand[0], operand[1]);
			break;
		}

		array = appendToArray(array, &value, sizeOfArray, tDouble);
	}

	//Calculate value of function
	if (isFunction(operator)) {
		switch (operator) {
		case constE:
		{
			double tmp = M_E;
			array = popArray(array, sizeOfArray, true, tDouble);
			array = appendToArray(array, &tmp, sizeOfArray, tDouble);
		}
			break;
		case constPi:
		{
			double tmp = M_PI;
			array = popArray(array, sizeOfArray, true, tDouble);
			array = appendToArray(array, &tmp, sizeOfArray, tDouble);
		}
			break;
		case factorial:
		{
			if (*sizeOfArray > 0) {
				double tmp = factorialFunction(array[*sizeOfArray - 1]);
				array = popArray(array, sizeOfArray, true, tDouble);
				array = appendToArray(array, &tmp, sizeOfArray, tDouble);
			}
		}
			break;
		case fsin:
		{
			if (*sizeOfArray > 0) {
				double tmp = sin(*array[*sizeOfArray - 1]);
				array = popArray(array, sizeOfArray, true, tDouble);
				array = appendToArray(array, &tmp, sizeOfArray, tDouble);
			}
		}
			break;
		case flog:
		{
			if (*sizeOfArray > 1) {
				double tmp = logarithmFunction(array[*sizeOfArray - 1], array[*sizeOfArray - 2]);
				array = popArray(array, sizeOfArray, true, tDouble);
				array = popArray(array, sizeOfArray, true, tDouble);
				array = appendToArray(array, &tmp, sizeOfArray, tDouble);
			}
		}
			break;
		};
	}

	return array;
}