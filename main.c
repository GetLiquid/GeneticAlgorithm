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


    /* 1. Create an initial, random population of critters */

    printf("initial generation (size %d):\n", POPULATION_SIZE);
    struct critter **population = malloc(sizeof(struct critter *) * POPULATION_SIZE);
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        population[i] = new_critter();
        print_critter(population[i]);
    }
    
    do
    {
      /* 2. Crossover the genomes of each critter with each other*/

      //array of critters of size POPULATION_SIZE^2 to accomodate all possible offspring
      struct critter **generation = malloc(sizeof(struct critter *) * POPULATION_SIZE * POPULATION_SIZE);
      
      for(int i=0;i<POPULATION_SIZE;++i)
      {
        for (int j = 0; j < POPULATION_SIZE; ++j)
        {
          //breed population[i] with population[j] and store in generation
          generation[i * POPULATION_SIZE + j] = crossover(population[i], population[j]);
          //print_critter(generation[i*POPULATION_SIZE+j]);
        }
      }

      /* 3. Sort the offspring by fitness to choose the POPULATION_SIZE best genomes to be bred again */

      merge_sort(generation, 0, POPULATION_SIZE * POPULATION_SIZE - 1, POPULATION_SIZE * POPULATION_SIZE);
      printf("best in generation (size %d): \n", POPULATION_SIZE * POPULATION_SIZE);
      for(int i=0; i < POPULATION_SIZE;++i)
      {
          print_critter(generation[i]);
      }


      /* 4. The fittest offspring become the parents of the next generation */

      for(int i=0;i<POPULATION_SIZE;++i)
      {
        free(population[i]);
        population[i] = generation[i];
      }
      for(int i=POPULATION_SIZE;i<POPULATION_SIZE * POPULATION_SIZE;++i)
      {
        free(generation[i]);
      }

    } while(population[0]->fitness < INFINITY);


    return 0;
}
