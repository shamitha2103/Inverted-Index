#include "invert.h"

int create_table(table_t *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i].ind = i;
        arr[i].link = NULL;
    }
    return 1;
}