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

    int last_op_index = -1;
    for(int i=low;i<=high;++i)
    {
      printf("%c", array[i]);

    }

    return NULL;
}
