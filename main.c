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

    struct critter *population[8];
    for(int i=0;i<8;++i)
    {
        population[i] = new_critter();
    }

    struct critter *gold = NULL;
    struct critter *silv = NULL;

    while(1)
    {
        struct critter * temp[8];
        int index = 0;
        for(int i=0;i<4;++i)
        {
            temp[index] = crossover(population[i], population[i+4]);
        }

        for(int i=0;i<8;++i)
        {
            if(temp[i])
                print_critter(temp[i]);
        }

    }
    
    return 0;
}
