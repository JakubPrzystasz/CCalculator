#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

int getOperatorPriority(int operator) {
	/*
	Operator 	Priorytet

	( 	        0
	+ - )   	1
	* / %   	2
	^ 	        3

	*/
	switch (operator) {
	case 6:
		return 0;
	case 0: case 1: case 7:
		return 1;
	case 2: case 3: case 5:
		return 2;
	case 4:
		return 3;
	}
	return -1;
}