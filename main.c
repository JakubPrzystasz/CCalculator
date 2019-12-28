#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{

	char* string = 0;
	
	string = appendToString(string,"pi/2");

	printf("%lf\n", calculateString(string));

	return 0;
}
