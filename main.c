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

    printf("\nThe population sorted by fitness in descending order:\n");
    merge_sort(population, 0, 7, 8);


    for(int i=0;i<8;++i)
    {
        printf("%.2f\n", fitness(population[i].gene));
    }


    return 0;
}
