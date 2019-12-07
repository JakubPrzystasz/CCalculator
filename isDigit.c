#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

/* CZY TO CYFRA */
bool isDigit(char expression) {
	if (((int)expression >= 48 && (int)expression <= 57) || (int)expression == 46) {
		return true;
	}
	return false;
}