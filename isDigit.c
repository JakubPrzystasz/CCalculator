#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdbool.h>

/* CZY TO CYFRA */
bool isDigit(char* expression) {
	if (strlen(expression) > 2) { return false; }
	bool flag = false;
	if (((int)expression[0] >= 48 && (int)expression[0] <= 57) || (int)expression[0] == 46) {
		flag = true;
	}
	return flag;
}