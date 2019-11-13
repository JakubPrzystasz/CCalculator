#include <stdio.h>
#include <stdlib.h>
#include "../inc/calculator.h"

static void freeArray(char** array, size_t size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}

