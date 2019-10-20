#include <stdio.h>
#include <stdlib.h>
#include "critter.h"
#include "util.h"

void print_tree(struct node *root)
{
    if(!root)
        return;
    print_tree_layer(root, 0);

}

void print_tree_layer(struct node *root, int layer)
{
    if(!root)
        return;

    printf("%d. ", layer);
    for(int i=0;i<layer;++i)
    {
        printf(" ");
    }
    printf("Node %c\n", root->data);
    print_tree_layer(root->left, layer+1);
    print_tree_layer(root->right, layer+1);

}
    

struct node *get_last_operator(char *array, int low, int high)
{
    if((high - low) == 0)
    {
        struct node * operand_node = malloc(sizeof(struct node));
        operand_node->data = array[low];
        operand_node->left = NULL;
        operand_node->right = NULL;
        return operand_node;
    }

    int last_op_index = low;
    for(int i=low;i<=high;++i)
    {
        if(op_comes_after(array[last_op_index], array[i]))
            last_op_index = i;
    }

    struct node *op_node = malloc(sizeof(struct node));
    op_node->data = array[last_op_index];
    op_node->left = get_last_operator(array, low, last_op_index - 1);
    op_node->right =get_last_operator(array, last_op_index+1, high);

    return op_node;
}
