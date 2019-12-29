#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

/* Convert double to readable string */
char* doubleToString(double value) {
    
    bool valueSign = value >= 0 ? true : false;

    char* string = 0;

    if (!valueSign) {
        value = -1 * value;
    }

    int intPart = (int)value;

    int fracPart = (int)((value - (double)intPart)*100000000);

    if (!valueSign) {
        string = appendToString(string, "-");
    }

    string = string = appendToString(string, intToString(intPart));

    string = appendToString(string,".");

    string = appendToString(string, intToString(fracPart));

    return string;

}
