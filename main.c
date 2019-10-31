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

    struct critter population[8];
    for(int i=0;i<8;++i)
    {
        population[i].id = 'A' +  (rand()%52);
        population[i].gene = rand();
        population[i].gene |= (uint64_t)rand() << 32;

        printf("%d\n", fitness());
    }

    quicksort(population, 0, 7);

    for(int i=0;i<8;++i)
    {
        print_critter(population+i);
    }


    
    return 0;
}
