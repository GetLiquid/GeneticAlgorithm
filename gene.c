#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "critter.h"
#include "util.h"

int fitness(char *genome);

int main()
{
    srand(time(NULL)*getpid());

    struct critter * crit_one = new_critter();
    struct critter * crit_two = new_critter();

    struct critter * crit_three = crossover(crit_one, crit_two);
    print_critter(crit_three);
    printf("%s\n", process_gene(crit_three));
    fitness(process_gene(crit_three));
    printf("\n");

    return 0;
}

int fitness(char *genome)
{
    struct node *root = get_last_operator(genome, 0, 0);
    if(root)
        printf("root: %c\n", root->data);
    return 0;
}
