#include "../calculator.h"

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
