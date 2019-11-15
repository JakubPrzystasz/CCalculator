#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
    WYKRYWANIE CZY TO FUNKCJA MATEMATYCZNA (CO ZROBIC Z ARGUMENTAMI?)
    USUWANIE OSTATNIEGO ELEMENTU TABICY 
    USUWANIE ELEMENTU ZE SRODKA TABLICY
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

/* SPRAWDZ CZY CIAG JEST LICZBA */
bool isNumber(char* expression){
    //check if the given string is a number
    int expLength = strlen(expression);
    char char1 = 0, char2 = 0;

    for (int i = 0; i < expLength; i++) {
        char1 = (int)expression[i];
        if(i+1<expLength) {
            char2 = (int)expression[i + 1];
        }else {
            char2 = 0;
        }
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

/* SPRAWDZ CZY CIAG JEST FUNKCJA */
bool isFunction(char* expression){
    int expLength = strlen(expression);
    char char1 = 0;

    for (int i = 0; i < expLength; i++) {
        char1 = (int)expression[i];

        switch (char1)
        {
            case '+':
                return false;
            case '-':
                return false;
            case '*':
                return false;
            case '/':
                return false;
            default:
                break;
        }
    }
    return true;
}

/* ROZBIERZ WPROWADZONY CIAG ZNAKOW NA TABLICE WYRAZEN */
char **parseExpression(char* expression){
    int count = 0, expLength = strlen(expression);
    char* string = 0;
    char** array = 0;
    char char1 = 0, char2 = 0;

    for (int i = 0; i < expLength; i++) {
        char1 = (int)expression[i];
        if(i+1<expLength) {
            char2 = (int)expression[i + 1];
        }else {
            char2 = 0;
        }
        //minus przed wyrazeniem -a+a -> 0-a+a
        if (i == 0 && char1 == '-') {
            array = appendToArray(array,"0",&count);
            array = appendToArray(array,"-",&count);
            continue;
        }
        if(i==0 && char1 == '.'){
            char tmp[3] = {'0','.','\0'};
            string = appendToString(string,tmp);
            continue;
        }
        if(i==0 && !(char1 >= 48 && char1 <= 57)){
            exit(1);
        }
        //znak jest cyfra
        if ((char1 >= 48 && char1 <= 57)
            || char1 == 46 && char2 >= 48 && char2 <= 57) {
            char tmp[2] = {expression[i],'\0'};
            string = appendToString(string,tmp);
            continue;
        }
        if((char1 == 46 && !(char2 >= 48 && char2 <= 57))
         || (char2 == 46 && !(char1 >= 48 && char1 <= 57))){
            exit(1);
        }
        if(!(char1 >= 48 && char1 <= 57) && char2 != 46){
            array = appendToArray(array,string,&count);
            string = 0;
            char tmp[2] = {expression[i],'\0'};
            string = appendToString(string,tmp);
            array = appendToArray(array,string,&count);
            string = 0;
        }
    }   

    //wrzuc to co zostalo w temp do tablicy
    if (string != 0) {
        array = appendToArray(array,string,&count);
    }

    for (int i = 0;i < count-1;i++) {
       if (isNumber(array[i]) && !isNumber(array[i+1]) && isFunction(array[i+1]) && !isFunction(array[i])) {
            //wrzuc * pomiedzy liczbe i nawias
            i += 1;
            array = insertToArray(array,"*\0", &count, i);
        }
    }

    /* *DEBUG* POKAZ TABLICE *DEBUG* */
        // printf("COUNT: %d\n",count);
        // for (int i = 0; i < count; i++) {
   		//     printf("[%d](%d)-> %s\n",i,isNumber(array[i]),array[i]);
   		// }
    /* *DEBUG*     *DEBUG*   *DEBUG* */

    return array;
}


double compute(char* expression){
	//get expression and compute value
	//    ArrayList<String> array = this.convertToArray(exp);
	//    array = this.convertToRNP(array);
	//    return this.compute(array);
	return 0;
}


int main(int argc, char** argv) {

    char** exp = parseExpression("43(34+44)");
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