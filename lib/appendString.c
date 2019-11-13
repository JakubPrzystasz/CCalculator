#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/calculator.h"

char *appendString(char* string, char* tail){
    if(string != 0) {
        string = (char *)realloc(string,(strlen((char*)string)+2)*sizeof(char));
        string = strcat(string,tail);
    }else{
        string = (char *)malloc(strlen(tail)*sizeof(char));
        string = strcpy(string,tail);
    }
    return string;
}
