#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "util.h"
#include "critter.h"

const int POPULATION_SIZE = 8;

int main()
{
    srand(time(NULL)*getpid());

    /*struct critter population[8];
    printf("8 randomly generated critters:\n");
    for(int i=0;i<8;++i)
    {
        population[i].id = 'A' +  (rand()%52);
        population[i].gene = rand();
        population[i].gene |= (uint64_t)rand() << 32;
        population[i].fitness = fitness(population[i].gene);

        printf("%.2f\n", population[i].fitness);
    }

    printf("\nTop 5 creatures this generation by fitness in descending order:\n");
    merge_sort(population, 0, 7, 8);


    int  i = 0;
    int  count = 0;
    while(i < 8 && count < 5)
    {
        if(fitness(population[i].gene) != INFINITY)
        {
            printf("%.2f\n", population[i].fitness);
            ++count;
        }
        ++i;
    }
*/
    struct critter **population = malloc(sizeof(struct critter *) * POPULATION_SIZE);
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        population[i] = new_critter();
        print_critter(population[i]);
    }
    merge_sort(population, 0, POPULATION_SIZE-1, POPULATION_SIZE);
    printf("\n");
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        print_critter(population[i]);
    }



    return 0;
}
