#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "critter.h"
#include "util.h"


float sum_tree(struct node *root)
{
    if(!root)
        return 0;

    if(!root->left || !root->right)
        return root->data - '0';

    float left_temp = sum_tree(root->left);
    float right_temp = sum_tree(root->right);
    float sum = 0;

    switch(root->data)
    {
        case '+':
            sum = left_temp + right_temp;
            break;
        case '-':
            sum = left_temp - right_temp;
            break;
        case 'x':
            sum = left_temp * right_temp;
            break;
        case '/':
            sum = left_temp / right_temp;
            break;
        defualt:
            break;
    }

    return sum;
}

int operator_comes_after(char a, char b) //returns 1 if b comes after a
{
    if(!is_operator(a))
        return 1;

    int a_index = 0;
    int b_index = 0;

    if(a == '+' || a == '-')
        a_index = 1;
    else
        a_index = 0;

    if(b == '+' || b == '-')
        b_index = 1;
    else
        a_index = 0;

    return b_index > a_index;
}

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
    

struct node *build_tree(char *array, int low, int high)
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
    for(int i=high;i>=low;--i)
    {
        if(operator_comes_after(array[last_op_index], array[i]))
            last_op_index = i;
    }

    struct node *op_node = malloc(sizeof(struct node));
    op_node->data  = array[last_op_index];
    op_node->left  = build_tree(array, low, last_op_index - 1);
    op_node->right = build_tree(array, last_op_index+1, high);
    return op_node;
}
