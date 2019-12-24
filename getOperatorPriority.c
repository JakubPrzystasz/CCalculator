#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

int getOperatorPriority(expType operator) {
	/*
	Operator 	Priorytet

	( 	        0
	+ - )   	1
	* / %   	2
	^ 	        3

	*/
	switch (operator) {
	case leftBracket:
		return 0;
	case addition: case subtraction: case rightBracket:
		return 1;
	case multiplication: case division: case modulo:
		return 2;
	case power:
		return 3;
	case function:
		return 4;
	}
	return -1;
}