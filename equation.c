#include <stdio.h>
#include "critter.h"

struct node *get_last_operator(char *array, int low, int high)
{
    printf("\nhigh - low = %d, %c\n", high - low, array[low]);
    if((high - low) == 0)
    {
        struct node * operand;
        operand->data = array[low];
        operand->left = NULL;
        operand->right = NULL;
        return operand;
    }
    return NULL;
}
