#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

bool isFunction(objectType operator) {

	if (!isOperator(operator) && !isConst(operator) && operator != undefined && operator != number && 
		operator != comma && operator != leftBracket && operator != rightBracket) {
		return true;
	}

	return false;
}