#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

int getOperatorTie(int operator) {
	/*
	Operator 	Priorytet

	// operators from 0 to 5
	

	*/

	//0 - left 1 - right

	switch (operator) {
	case 4:
		return 1;
	default:
		return 0;
	}

	return -1;
}