#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <math.h>

/* Calculate factorial of value */
double factorialFunction(double* value) {
	
	double tmp = 1;
	
	if (value > 0) {
		for (int i = 1; i <= (int)*value; i++) {
			tmp *= i;
		}
		return tmp;
	}

	return 0;
}