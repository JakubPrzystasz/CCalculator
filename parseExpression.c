#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* PARSE STRING TO ARRAY OF MATH EXPRESSIONS */
char** parseExpression(char* expression, int* length) {

	int count = 0;
	char* string = 0;
	char** array = 0;
	char char1 = 0, char2 = 0;
	//0 - number; 1- function
	bool expType = 0;

	//dodawaj do stringa dopóki nie napotkasz czegos co nie jest cyfra
	for (int i = 0; i < *length; i++) {
		char char1[2] = { expression[i],'\0' };
		if (i == 0) {
			array = appendToArray(array, "0", &count);
		}

		if (getOperator(char1) >= 0) {
			//natrafiono na operator
			if (string != 0) {
				array = appendToArray(array, string, &count);
				string = 0;
			}
			array = appendToArray(array, char1, &count);
		} else {
			if (string != 0) {
				if (!isNumber(char1) && expType == 0) {
					array = appendToArray(array, string, &count);
					string = 0;
					string = appendToString(string, char1);
					expType = 1;
				}
				else if (isNumber(char1) && expType == 1) {
					array = appendToArray(array, string, &count);
					string = 0;
					string = appendToString(string, char1);
					expType = 0;
				}
				else {
					string = appendToString(string, char1);
				}
			} else {
				string = appendToString(string, char1);
				if (isNumber(string)) {
					expType = 0;
				}
				else {
					expType = 1;
				}
			}
		}

		/* DEBUG */
		/*
		printf("STRING:%s | isNumber:%d | isDigit:%d | isFunc:%d | getOperator:%d | CHAR: %c \n",
		string,string!=0?isNumber(string):0,isDigit(char1),isFunction(char1),getOperator(   char1),char1);
		*/
		/* DEBUG */

	}

	//wrzuc to co zostalo w temp do tablicy
	if (string != 0) {
		array = appendToArray(array, string, &count);
	}

	for (int i = 0;i < count - 1;++i) {
		if (isNumber(array[i]) && isFunction(array[i + 1])) {
			array = insertToArray(array, "*\0", &count, i + 1);
			i += 1;
			continue;
		}
		if (isNumber(array[i]) && getOperator(array[i + 1]) == 6) {
			array = insertToArray(array, "*\0", &count, i + 1);
			i += 1;
			continue;
		}
	}

	/* *DEBUG* POKAZ TABLICE *DEBUG* */
	/*
	printf("COUNT: %d\n",count);
	for (int i = 0; i < count; i++) {
		   printf("[%d]-> %s\n",i,array[i]);
	   }

/* *DEBUG*     *DEBUG*   *DEBUG* */

	*length = count;
	return array;
}
