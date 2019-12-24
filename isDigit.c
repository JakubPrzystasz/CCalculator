#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdbool.h>

/* Check if given character is a part of number */
bool isDigit(char expression) {

	if (((int)expression >= 48 && (int)expression <= 57) || (int)expression == 46) {
		return true;
	}
	return false;

}