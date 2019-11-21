#include "calculator.h"
#include <stdlib.h>

/* CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION */
int toPOSTFIX(char** expressionArray, int* length) {
	//queue
	char** output = 0;
	//stack
	char** stack = 0;
	int countOutput = 0, countStack = 0, stackI = 0;

	/*DEBUG*/
	/*
		for (int i = 0; i < *length; i++) {
			printf("[%d]{%d}-> %s\n",i,strlen(expressionArray[i]),expressionArray[i]);
		}

	/*DEBUG*/

	for (int i = 0;i < *length;i++) {


		//        printf("(%d)EXPRESSION:%s\nSTACK:",i,expressionArray[i]);
		//        for(int x=0;x<countStack;x++){
		//            printf("%s ",stack[x]);
		//        }
		//        printf("\nQUEUE:");
		//        for(int x=0;x<countOutput;x++){
		//            printf("%s ",output[x]);
		//        }
		//        printf("\n");


		if (isNumber(expressionArray[i])) {
			output = appendToArray(output, expressionArray[i], &countOutput);
			continue;
		}

		if (isFunction(expressionArray[i])) {
			output = appendToArray(output, expressionArray[i], &countOutput);
			continue;
		}

		if (getOperator(expressionArray[i]) == 8) {
			stackI = countStack - 1;
			while (getOperator(stack[stackI]) != 6) {
				output = appendToArray(output, stack[stackI], &countOutput);
				stack = popArray(stack, &countStack);
				stackI -= 1;
			}
			continue;
		}

		if (getOperator(expressionArray[i]) == 6) {
			stack = appendToArray(stack, expressionArray[i], &countStack);
			continue;
		}

		if (getOperator(expressionArray[i]) == 7) {
			stackI = countStack - 1;
			while (getOperator(stack[stackI]) != 6) {
				output = appendToArray(output, stack[stackI], &countOutput);
				stack = popArray(stack, &countStack);
				stackI -= 1;
			}
			stack = popArray(stack, &countStack);
			continue;
		}

		if (getOperator(expressionArray[i]) >= 0 && 5 >= getOperator(expressionArray[i])) {
			stackI = countStack - 1;
			//stos pusty lub priorytet jest wiekszy
			if (countStack == 0) {
				stack = appendToArray(stack, expressionArray[i], &countStack);
				continue;
			}
			if (getOperatorPriority(getOperator(stack[stackI])) < getOperatorPriority(getOperator(expressionArray[i]))) {
				stack = appendToArray(stack, expressionArray[i], &countStack);
				continue;
			}
			else {
				//wiekszy lub rowny priorytet na stosie
				for (stackI;stackI >= 0;stackI--) {
					if (getOperatorPriority(getOperator(stack[stackI])) < getOperatorPriority(getOperator(expressionArray[i]))) {
						stack = appendToArray(stack, expressionArray[i], &countStack);
						break;
					}
					else {
						output = appendToArray(output, stack[stackI], &countOutput);
						stack = popArray(stack, &countStack);
					}
				}
			}
		}
	}

	//ZWOLNIJ ELEMENTY ZE STOSU I PRZEKARZ DO WYJSCIA
	stackI = countStack - 1;
	while (countStack > 0) {
		output = appendToArray(output, stack[stackI], &countOutput);
		stack = popArray(stack, &countStack);
		stackI -= 1;
	}

	/*
   printf("STACK:");
   for(int i=0;i<countStack;i++){
	   printf("%s ",stack[i]);
   }
   printf("\n");
   for(int i=0;i<countOutput;i++){
	   printf("%s ",output[i]);
	}
	printf("\n");
	*/

	* length = countOutput;

	return output;
}