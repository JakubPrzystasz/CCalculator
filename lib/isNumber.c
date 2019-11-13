#include "../inc/calculator.h"

bool isNumber(char* expression){
    //check if the given string is a number
    int expLength = strlen(expression);
    int char1 = 0, char2 = 0;
    for (int i = 0; i+1 < expLength; i++) {
        char1 = (int)expression[i];
        char2 = (int)expression[i+1];
        //check all combinations of digits stored in chars
        //we have integers, and floating point numbers with dot
        //if none of these conditions are true return false
        if (!((char1 >= 48 && char1 <= 57) ||
              ((char1 >= 48 && char1 <= 57 && char2 == 46) || (char2 >= 48 && char2 <= 57 && char1 == 46)))
            //something like .01 or 1. is invalid value
            || (i+1 == expLength-1 && char2 == 46) || (i==0 && char1 == 46)){
            //chars are the part of float number because of that we have a dot between total and fractional part
            return false;
        }
    }

    return true;
}

