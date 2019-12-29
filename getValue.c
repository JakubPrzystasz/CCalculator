#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Convert infix to postfix */
char* getValue(objectType operator) {

	switch (operator) {
		case constE:
		{
			return doubleToString(M_E);
		}
		break;
		case constPi:
		{
			return doubleToString(M_PI);
		}
	};
}