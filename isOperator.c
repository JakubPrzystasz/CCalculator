#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

bool isOperator(expType operator) {

	switch (operator) {
		case addition: case subtraction: case multiplication: case division:
		case power: case modulo:
			return true;
		default:
			return false;
	};

	return false;
}