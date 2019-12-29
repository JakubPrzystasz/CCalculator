#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

bool isConst(objectType operator) {

	switch (operator)
	{
	case constE: case constPi:
		return true;
	default:
		return false;
	}
}