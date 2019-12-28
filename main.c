#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	char* string = 0;
	//string = appendToString(string,"!5");

	string = doubleToString(-11.111);
	printf("%s\n", string);

	string = trimString(string, '0');
	printf("%s\n", string);

	string = emptyString(string);

	string = appendToString(string,"HelloWorld!");
	string = popString(string);
	printf("%s\n", string);

	//printf("%lf\n", calculateString(string));

	return 0;
}
