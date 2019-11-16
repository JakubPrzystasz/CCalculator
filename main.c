#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    WYKRYWANIE CZY TO FUNKCJA MATEMATYCZNA (CO ZROBIC Z ARGUMENTAMI?)
*/

/* DODAJ STRING NA KONIEC TABLICY*/
char **appendToArray(char** array,char* string,int* count){
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

/* EDYTUJ WARTOSC W TABLICY */
char **editInArray(char **array,char* string,int* count,int index){
    if(index >= *count){exit(1);}
    array[index] = (char *)realloc(array[index],(strlen((char*)string)+1)*sizeof(char));
    if (array[index] == 0)
        exit(1);
    strcpy(array[index],string);
    return array;
}

/* DOPISZ DO TABICY WARTOSC WE WSKAZANYM MIEJSCU */
char **insertToArray(char** array,char* string,int* count,int index){
    int length = *count;
    if(index > length) {exit(1);}
    if(index == length) {
        array = appendToArray(array,string,&length);
        *count = length;
        return array;
    }

    array = (char **) realloc(array, (length + 1) * sizeof(*array));
    if (array == NULL){
        exit(1);
    }

    char **tempArray = 0;
    int countTemp = 0;
    tempArray = appendToArray(tempArray,string,&countTemp);
    for(int i = 0;i<(length - index);i++){
        tempArray = appendToArray(tempArray,array[index+i],&countTemp);
    }

    for(int i = 0;i<(length - index);i++){
        array = editInArray(array,tempArray[i],&length,i+index);
    }
    array = appendToArray(array,tempArray[length - index],&length);
    *count = length;
    return array;
}

/* USUŃ OSTANIA WARTOŚĆ */
char **popArray(char** array,int* count){
    free(array[*count-1]);
    array = (char **) realloc(array, (*count - 1) * sizeof(*array));
    *count -= 1;
    return array;
}

/* USUN WARTOSC WE WSKAZANYM INDEKSIE */
char **removeInArray(char** array,int* count,int index){
    int length = *count;
    if(index >= length){ exit(1);}
    if(index+1 == length) {
        array = popArray(array,&length);
        *count = length;
        return array;
    }

    free(array[index]);

    char **tempArray = 0;
    int countTemp = 0;
    for(int i = 1;i<(length - index);i++){
        tempArray = appendToArray(tempArray,array[index+i],&countTemp);
    }

    array = (char **) realloc(array, (length - 1) * sizeof(*array));

    for(int i = 0;i+1<(length - index);i++){
        array = editInArray(array,tempArray[i],&length,i+index);
    }

    *count = length-1;
    return array;
}

/* DOPISZ WARTOSC NA KONIEC STRINGA */
char *appendToString(char* string, char* tail){
    if(string != 0) {
        string = (char *)realloc(string,(strlen((char*)string)+2)*sizeof(char));
        string = strcat(string,tail);
    }else{
        string = (char *)malloc(strlen(tail)*sizeof(char));
        string = strcpy(string,tail);
    }
    return string;
}

/* ZWOLNIJ PAMIEC Z TABICY */
static void freeArray(char** array, size_t size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}

/* CZY TO CYFRA */
bool isDigit(char* expression){
    if(strlen(expression) > 2) { return false;}
    bool flag = false;
    if(((int)expression[0] >=48 && (int)expression[0] <= 57) || (int)expression[0] == 46){
        flag = true;
    }
    return flag;
}

/* SPRAWDZ CZY CIAG JEST LICZBA */
bool isNumber(char* expression){
    //check if the given string is a number
    int expLength = strlen(expression);
    if(expLength < 1){ return false;}
    char char1 = 0;
    bool flag = true;

    for (int i = 0; i < expLength; i++) {
        char1 = expression[i];
        //check all combinations of digits stored in chars
        //we have integers, and floating point numbers with dot
        //if none of these conditions are true return false
        if(!isDigit(&char1)){
            flag = false;
        }
    }

    return flag;
}

/* SPRAWDZ CZY CIAG JEST OPERATOREM */
int getOperator(char* expression){
    if(strlen(expression) > 2){ return -1;}
    switch (expression[0])
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '^':
            return 4;
        case '%':
            return 5;
        case '(':
            return 6;
        case ')':
            return 7;
        case ',':
            return 8;
    }

    return -1;
}

int getOperatorPriotiy(int operator){
    /*
    Operator 	Priorytet

    ( 	        0
    + - )   	1
    * / %   	2
    ^ 	        3

    */
    switch(operator){
        case 6:
            return 0;
        case 0: case 1: case 7:
            return 1;
        case 2: case 3: case 5:
            return 2;
        case 4:
            return 3;
    }
    return -1;
}

/* SPRAWDZ CZY TO FUNKCJA */
bool isFunction(char* expression){
    int expLength = strlen(expression);
    bool flag = true;
    for(int i=0;i<expLength;i++){
        if((int)expression[i] < 97 || (int)expression[i] > 122){
            flag = false;
        }
    }
    return flag;
}

/* ROZBIERZ WPROWADZONY CIAG ZNAKOW NA TABLICE WYRAZEN */
char **parseExpression(char* expression,int* length){
    int count = 0;
    char* string = 0;
    char** array = 0;
    char char1 = 0, char2 = 0;
    //0 - number; 1- function
    bool expType = 0;


    if(expression[0] == '-'){ array = appendToArray(array,"0",&count); }
    //dodawaj do stringa dopóki nie napotkasz czegos co nie jest cyfra
    for (int i = 0; i < *length; i++) {
        char char1[2] = {expression[i],'\0'};

        if(getOperator(char1) >= 0){
            //natrafiono na operator
            if(string != 0){
                array = appendToArray(array,string,&count);
                string = 0;
            }
            array = appendToArray(array,char1,&count);
        }else{
            if(string != 0){
                if(!isNumber(char1) && expType == 0){
                    array = appendToArray(array,string,&count);
                    string = 0;
                    string = appendToString(string,char1);
                    expType = 1;
                }else if(isNumber(char1) && expType == 1){
                    array = appendToArray(array,string,&count);
                    string = 0;
                    string = appendToString(string,char1);
                    expType = 0;
                }else{
                    string = appendToString(string,char1);
                }
            }else{
                string = appendToString(string,char1);
                if(isNumber(string)){
                    expType = 0;
                }else{
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
        array = appendToArray(array,string,&count);
    }

    for(int i=0;i<count-1;++i){
        if(isNumber(array[i]) && isFunction(array[i+1])){
            array = insertToArray(array,"*\0",&count,i+1);
            i+=1;
            continue;
        }
        if(isNumber(array[i]) && getOperator(array[i+1]) == 6){
            array = insertToArray(array,"*\0",&count,i+1);
            i+=1;
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

/* CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION */
char **toPOSTFIX(char** expressionArray,int* length){
    char* input = 0;
    //queue
    char** output = 0;
    //stack
    char** stack = 0;
    int countOutput = 0, countStack = 0, stackI = 0;

//DEBUG
/*
    for (int i = 0; i < *length; i++) {
        printf("[%d]{%d}-> %s\n",i,strlen(expressionArray[i]),expressionArray[i]);
    }

/*DEBUG*/

    for(int i=0;i<*length;i++){

        if(isNumber(expressionArray[i])){
            output = appendToArray(output,expressionArray[i],&countOutput);
            continue;
        }

        if(isFunction(expressionArray[i])){
            output = appendToArray(output,expressionArray[i],&countOutput);
            continue;
        }

        if(getOperatorPriotiy(expressionArray[i]) == 8){
            stackI = countStack - 1;
            while(getOperator(stack[stackI]) != 6){
                output = appendToArray(output,stack[stackI],&countOutput);
                stack = popArray(stack,&countStack);
                stackI -= 1;
            }
        }

        if(getOperator(expressionArray[i]) == 6){
            stack = appendToArray(stack,expressionArray[i],&countStack);
        }

        if(countStack > 0 && getOperator(expressionArray[i]) >= 0 && 6 > getOperator(expressionArray[i])){
            stackI = countStack - 1;
            int oper1 = getOperator(expressionArray[i]);
            int oper2 = getOperator(stack[stackI]);
            int p1 = getOperatorPriotiy(oper1);
            int p2 = getOperatorPriotiy(oper2);
            while(p1 <= p2){
                output = appendToArray(output,stack[stackI],&countOutput);
                stack = popArray(stack,&countStack);
                stackI -= 1;
            }
            output = appendToArray(output,expressionArray[i],&countOutput);
        }

        if(getOperator(expressionArray[i]) == 7){
            stackI = countStack - 1;
            while(getOperator(stack[stackI]) != 6){
                output = appendToArray(output,stack[stackI],&countOutput);
                stack = popArray(stack,&countStack);
                stackI -= 1;
            }
        }

//
//        if(getOperator(expressionArray[i]) == 6){
//            stack = appendToArray(stack,expressionArray[i],&countStack);
//            continue;
//        }
//
//        if(getOperator(expressionArray[i]) == 7){
//            stackI = countStack - 1;
//            while(true){
//                if(stackI == 0){break;}
//                if(getOperator(stack[stackI]) == 6){
//                    stack = popArray(stack,&countStack);
//                    break;
//                }
//                output = appendToArray(output,stack[stackI],&countOutput);
//                stack = popArray(stack,&countStack);
//                stackI -= 1;
//            }
//            continue;
//        }
//
//        if(getOperator(expressionArray[i]) >= 0 && 5 >= getOperator(expressionArray[i])){
//
//            if(countStack == 0){
//                stack = appendToArray(stack,expressionArray[i],&countStack);
//                continue;
//            }
//            if(getOperatorPriotiy(getOperator(expressionArray[i])) > getOperatorPriotiy(*stack[countStack-1])){
//                stack = appendToArray(stack,expressionArray[i],&countStack);
//                continue;
//            }
//            stackI = countStack -1;
//            do{
//                output = appendToArray(output,stack[stackI],&countOutput);
//                stack = popArray(stack,&countStack);
//                stackI -= 1;
//            }
//            while(countStack > 0 && getOperatorPriotiy(*stack[stackI]));
//            continue;
//        }
    }
    stackI = countStack - 1;
    do{
        output = appendToArray(output,stack[stackI],&countOutput);
        stack = popArray(stack,&countStack);
        stackI -= 1;
    }while(countStack > 0);

    printf("STACK:");
    for(int i=0;i<countStack;i++){
        printf("%s ",stack[i]);
    }
    printf("\n");
    for(int i=0;i<countOutput;i++){
        printf("%s ",output[i]);
    }
    printf("\n");
}

/*DO THE MATH*/
double compute(char** expressionArray,int* length){

}

/*CALCULATE MATH EXPRESSION*/
double calculate(char* expression,int* length){

    char** expressionArray = parseExpression(expression,length);
    expressionArray = toPOSTFIX(expressionArray,length);

    return 0;
}


int main(int argc, char** argv) {

    int length=0;
    char *input = 0;
    input = appendToString(input,"3+4*2/(1-5)^2\0");
    length = strlen(input);
    double x = calculate(input,&length);
    printf("3 4 2 * 1 5 - 2 ^ / +\n");


/* TO NA ODCZYT Z LINII POLECEN */
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
