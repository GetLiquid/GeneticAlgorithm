#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "tree.h"
#include "util.h"
#include "critter.h"

float fitness(char *genome);
float sum_tree(struct node *root);

int main()
{
    srand(time(NULL)*getpid());

    struct critter * gold = NULL;
    struct critter * silver = NULL;
    float gold_fit = 0.0;
    float silv_fit = 0.0;

    struct critter * generation[8];
    for(int i=0;i<8;++i)
    {
        generation[i] = new_critter();
        print_critter(generation[i]);
    }

    printf("\n");

    gold = generation[0];
    silver = generation[0];
    for(int i=0;i<4;++i)
    {
        struct critter *new_crit = crossover(generation[i], generation[2*i+4]);
        print_critter(new_crit);
    }


    return 0;
}
