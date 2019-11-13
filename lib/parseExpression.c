#include "../inc/calculator.h"

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

