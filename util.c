#include "critter.h"
#include "util.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int is_number(char c) {return c >= '0' && c <= '9';}
int is_operator(char c) {return (c == '+') || (c == '-') || (c == 'x') || (c == '/');}

void print_bitset(uint64_t in)
{
    for(int i=0;i<sizeof(in)*2;++i)
    {
        uint8_t temp = (uint8_t) (in >> i*4) & 0xF;
        for(int i=3;i>=0;--i)
        {
            if(1 & (temp >> i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}

int str_length(const char *input)
{
    int count = 0;
    while(*(input + count))
        ++count;
    return count;
}

void exchange_critter(struct critter *A, struct critter *B)
{
    struct critter temp;
    temp.id = A->id;
    temp.gene = A->gene;

    A->id = B->id;
    A->gene = B->gene;

    B->id = temp.id;
    B->gene = temp.gene;
}

struct critter * copy_critter(struct critter *from)
{
    struct critter * to = malloc(sizeof(struct critter));
    to->id = from->id;
    to->gene = from->gene;
    return to;
}

float fitness(uint64_t gene, int target)
{
    char * process = process_gene(gene);
    struct node *root = build_tree(process, 0, str_length(process) - 1);
    float tree_sum = sum_tree(root);
    delete_tree(root);
    free(process);
    return 1 / (target - tree_sum);
}

float fitness_char(char *gene, int target)
{
    struct node *root = build_tree(gene, 0, str_length(gene)-1);
    float tree_sum = sum_tree(root);
    delete_tree(root);
    return 1 / (target - sum_tree(root));
}

