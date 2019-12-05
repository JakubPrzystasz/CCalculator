#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main()
{
	char* expression = 0;
	expression = appendToString(expression, "5(5+5)\0");
	int length = strlen(expression);
	double x = calculate(expression, &length);
	printf("%lf\n", x);
	return 0;
}
