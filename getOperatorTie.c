#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

int getOperatorTie(expType operator) {

	//0 - left 1 - right

	switch (operator) {
	case power:
		return 1;
	default:
		return 0;
	}

	return -1;
}