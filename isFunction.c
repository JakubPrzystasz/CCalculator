#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"

/* SPRAWDZ CZY TO FUNKCJA */
bool isFunction(char* expression) {
	int expLength = strlen(expression);
	bool flag = true;
	for (int i = 0;i < expLength;i++) {
		if ((int)expression[i] < 97 || (int)expression[i] > 122) {
			flag = false;
		}
	}
	return flag;
}