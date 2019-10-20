#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "critter.h"
#include "util.h"

float fitness(char *genome);
float sum_tree(struct node *root);

int main()
{
    srand(time(NULL)*getpid());

    //char *gene = "9+4/3-4";
    struct critter *a = new_critter();
    char *a_gene = process_gene(a);
    printf("Equation: %s\nFitness: %f\n", a_gene, fitness(a_gene));

    return 0;
}


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

float fitness(char *genome)
{
    struct node *root = get_last_operator(genome, 0, gene_length(genome)-1);
    print_tree(root);
    return sum_tree(root);
}
