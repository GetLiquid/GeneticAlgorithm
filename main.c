#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "util.h"
#include "critter.h"

const int POPULATION_SIZE = 8;

int main(int argc, char **argv)
{
    int sum_target = 0;
    if(argc > 1)
    {
        sum_target = atoi(argv[1]);
    } else
    {
        printf("Target: ");
        scanf("%d", &sum_target);
    }
    
    uint64_t seed = time(NULL)*getpid();
    srand(seed);
    
    clock_t start, end;

    /* 1. Create an initial, random population of critters */

    printf("initial generation (size %d):\n", POPULATION_SIZE);
    struct critter **population = malloc(sizeof(struct critter *) * POPULATION_SIZE);
    for(int i=0;i<POPULATION_SIZE;++i)
    {
        population[i] = new_critter(sum_target);
        print_critter(population[i]);
        printf("\n");
    }
    
    int generation_count = 1;
    start = clock();
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
          generation[i * POPULATION_SIZE + j] = crossover(population[i], population[j], sum_target);
        }
      }

      /* 3. Sort the offspring by fitness to choose the POPULATION_SIZE best genomes to be bred again */
      
      merge_sort(generation, 0, POPULATION_SIZE * POPULATION_SIZE - 1, POPULATION_SIZE * POPULATION_SIZE);

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
      free(generation);

      ++generation_count;
      ++seed;
      srand(seed);
      printf("\r Best of generation %d | ", generation_count);
      print_critter(population[0]);

    /* Repeat the breeding process until the program reaches the target sum */

    } while(population[0]->fitness < INFINITY);
    end = clock();
    double sec_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    char * processed = process_gene(population[0]->gene);
    struct node *root = build_tree(processed, 0, str_length(processed) - 1);
    printf("\nProcessed %d generations in %lf seconds\nEquation: %s, Sum: %.1f, Target: %d\n", generation_count, sec_elapsed, processed, sum_tree(root), sum_target);
    free(processed);
    delete_tree(root);
    free(population);

    for(int i=0;i<POPULATION_SIZE;++i)
    {
        free(population[i]);
    }


    return 0;
}
