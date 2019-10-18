#include <stdio.h>
#include "critter.h"
#include "util.h"

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

    int last_op_index = low;
    for(int i=low;i<=high;++i)
    {
        if(is_operator(aray[i]) && op_omes_after(array[i], array[last_op_index]))
        {

        }
    }

    return NULL;
}
