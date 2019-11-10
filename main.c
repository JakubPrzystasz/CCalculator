#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "calculator.h"

double compute(char* expression);
bool isNumber(char* expression);
char **parseExpression(char* exp);

int main(int argc, char** argv) {

    char** exp = parseExpression("12+123");
//    char* inputString;
//    size_t inputStringSize;
//    char* str = (char*)malloc(30 * sizeof(char));
//    strcpy(str,"Ala ");
//    char *strFrom = "ma kota\n";   // zapisujemy wskaznik na napis
//    strcat (str, strFrom);
//    printf("%s",str);
//    free(str);
    //READ ARGS FROM COMMAND LINE
    //printf("%s",argv[1]);
//    printf("INPUT:");
//    if(getline(&inputString, &inputStringSize, stdin) != (-1))
//    {
//        printf("RESULT: %lf\n",compute(inputString));
//    }

    return 0;
}

double compute(char* expression){
    //get expression and compute value
//    ArrayList<String> array = this.convertToArray(exp);
//    array = this.convertToRNP(array);
//    return this.compute(array);
    return 0;
}

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

static void freeArray(char** array, size_t size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}

char **appendArray(char** array,char* string,int* count){
    array = (char **) realloc(array, (*count + 1) * sizeof(*array));
    if (array == NULL)
        exit(1);
    array[*count] = (char *)malloc((strlen((char*)string)+1)*sizeof(char));
    if (array[*count] == 0)
        exit(1);
    strcpy(array[*count],string);
    *count = *count + 1;
    return array;
}

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

char **parseExpression(char* expression){
    int count = 0, expLength = strlen(expression);
    char* string = 0;
    char** array = 0;
    char char1 = 0, char2 = 0;

//    char tmp[2] = {expression[0],'\0'};
//    string = appendString(string,tmp);
//    tmp[0] = expression[1];
//    string = appendString(string,tmp);
//    array = appendArray(array,string,&count);
//    array = appendArray(array,string,&count);
//    printf("%s",string);

    for(int i=0;i<expLength;i++)
    {
        char tmp[2]={expression[i],'\0'};
        int x = (int)expression[i];
        if(string != 0 && (!(x>47 && x<58) || i+1 == expLength)){
            array = appendArray(array,string,&count);
            free(string);
            string = 0;
            continue;
        }
        string = appendString(string,tmp);
        printf("%s\n",string);
    }

    for(int i=0;i<count;i++){
        //printf("%s\n",array[i]);
    }

    free(string);
    freeArray(array,count);

//    for (int i = 0; i < expLength; i++) {
//        char1 = (int)expression[i];
//        char2 = (int)expression[i+1];
//
//        //minus przed wyrazeniem -a+a -> 0-a+a
//        if (i == 0 && char1 == '-') {
//            array = appendArray(array,"0",&count);
//            array = appendArray(array,"-",&count);
//        }
//        //sprawdz czy znak jest cyfra
//        else if (char1 >= 48 && char1 <= 57) {
//            string = appendString(string,char1);
//        }
//        //znak jest kropka w liczbie zmiennoprzecinkowej
//        else if (char1 == 46 && char2 >= 48 && char2 <= 57) {
//            if (string == 0) {
//            //gdyby ktos napisal .222 popraw na 0.2222
//                string = appendString(string,"0");
//            }
//            string = appendString(string,char1);
//        } else {
//            if (string != 0) {
//                array = appendArray(array,string,count);
//            }
//            string = appendString(string,char1);
//            if (string != ".") {
//                array = appendArray(array,string,count);
//            }
//            string = 0;
//            //jesli wystapi cos takiego : (-a-a) wstaw zero -> (0-a-a)
//            if (char1 == 40 && char2 == 45) {
//                array = appendArray(array,"0",count);
//            }
//        }
//    }
//
//    //wrzuc to co zostalo w temp do tablicy
//    if (string != 0) {
//        array = appendArray(array,string,count);
//    }
//
//    for (int i = 0; i+1 < count; i++) {
//        if (isNumber(array[i]) && array[i+1] == "(") {
//            //wrzuc * pomiedzy liczbe i nawias
//            array = addToArray("*", array, i);
//        }
//    }
//     /*DEBUG* pokaz tablice *DEBUG*/
//    		 for (int i = 0; i < count; i++) {
//    		     printf("%s\n",array[i]);
//    		 }
//    		 printf("%d\n",count);
    /*DEBUG*     *DEBUG*   *DEBUG*/
    //return temp;
    return 0;
}