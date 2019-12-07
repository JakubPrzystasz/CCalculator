#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

/* SPRAWDZ CZY TO FUNKCJA */
bool isFunction(char* expression) {
	int expLength = strlen(expression);

	for (int i = 0;i < expLength;i++) {
		if ((int)expression[i] < 97 || (int)expression[i] > 122) {
			return false;
		}
	}

	return true;
}