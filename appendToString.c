#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* DOPISZ WARTOSC NA KONIEC STRINGA */

int appendToString(char* string, char* tail) {
	if (string != 0) {
		string = (char*)realloc(string, (strlen((char*)string) + 2) * sizeof(char));
		if (string == NULL) {
			return -1;
		}
		string = strcat(string, tail);
	} else {
		string = (char*)malloc(strlen(tail) * sizeof(char));
		if (string == NULL) {
			return -1;
		}
		string = strcpy(string, tail);
	}
	return 0;
}