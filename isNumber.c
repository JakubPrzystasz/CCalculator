#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

/* SPRAWDZ CZY CIAG JEST LICZBA */
bool isNumber(char* expression) {
	//check if the given string is a number
	int expLength = strlen(expression);
	if (expLength < 1) { return false; }

	for (int i = 0; i < expLength; i++) {
		//check all combinations of digits stored in chars
		//we have integers, and floating point numbers with dot
		//if none of these conditions are true return false
		if (isDigit(expression[i]) == 0) {
			return false;
		}
	}

	return true;
}