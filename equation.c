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
        if(op_comes_after(array[last_op_index], array[i]))
        {
            last_op_index = i;
        }
    }
    printf("%c", array[last_op_index]);

    struct node *op_node;
    op_node->data = array[last_op_index];
    op_node->left = get_last_operator(array, 0, last_op_index - 1);
    op_node->right =get_last_operator(array, last_op_index+1, high);

    return op_node;
}
