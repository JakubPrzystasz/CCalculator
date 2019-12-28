#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <math.h>

/* Calculate logarithm */
double logarithmFunction(double* base, double* value) {

	return (log(*base) / log(*value));
}