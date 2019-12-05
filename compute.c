#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*DO THE MATH*/
double compute(char** expressionArray, int* length) {
	char** stack = 0;
	int countStack = 0;
	char* arg1 = 0;
	char* arg2 = 0;
	double result = 0;

	for (int i = 0;i < *length;i++) {
		for (int x = 0;x < countStack;x++) {
			printf("%s,", stack[x]);
		}
		printf("EXP:%s", expressionArray[i]);

		printf("\n");

		if (countStack > 0) {
			arg1 = appendToString(arg1, stack[countStack - 1]);
		}
		if (countStack > 1) {
			arg2 = appendToString(arg2, stack[countStack - 2]);
			printf("ARGS:%s   %s\n", arg1, arg2, expressionArray[i], doMath(getOperator(expressionArray[i]), arg1, arg2));
		}

		if (isNumber(expressionArray[i])) {
			stack = appendToArray(stack, expressionArray[i], &countStack);
			continue;
		}

		if (getOperator(expressionArray[i]) >= 0 && 5 >= getOperator(expressionArray[i]) && countStack > 1) {
			stack = popArray(stack, &countStack);
			stack = popArray(stack, &countStack);
			stack = appendToArray(stack, doMath(getOperator(expressionArray[i]), arg1, arg2), &countStack);

			/*printf("STACK:\n");
			for(int x=0;x<countStack;x++){
				//printf("%s\n",stack[x]);
			}
			*/

		}
	}

	result = atof(stack[0]);
	//freeArray(stack, countStack);
	return  result;
}