#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "util.h"
#include "critter.h"

int main()
{
    srand(time(NULL)*getpid());

    struct critter population[8];
    printf("8 randomly generated critters:\n");
    for(int i=0;i<8;++i)
    {
        population[i].id = 'A' +  (rand()%52);
        population[i].gene = rand();
        population[i].gene |= (uint64_t)rand() << 32;

        printf("%.2f\n", fitness(population[i].gene));
    }

    printf("\nTop 4 creatures this generation by fitness in descending order:\n");
    merge_sort(population, 0, 7, 8);


    int  i = 0;
    int  count = 0;
    while(i < 8 && count < 4)
    {
        if(fitness(population[i].gene) != INFINITY)
        {
            printf("%.2f\n", fitness(population[i].gene));
            ++count;
        }
        ++i;
    }

    return 0;
}
