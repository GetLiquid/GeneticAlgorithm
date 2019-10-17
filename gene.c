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
    print_critter(crit_one);
    printf("%s\n", process_gene(crit_one));

    struct critter * crit_two = new_critter();
    print_critter(crit_two);
    printf("%s\n", process_gene(crit_two));

    struct critter * crit_three = crossover(crit_one, crit_two);
    print_critter(crit_three);
    printf("%s\n", process_gene(crit_three));
    fitness(process_gene(crit_three));

    printf("\n");

    return 0;
}

int fitness(char *genome)
{
    char *cur = genome + 1;
    while(*cur)
    {
        switch(*cur)
        {
            case 'x':
                printf("%d", (*(cur-1) - '0') * (*(cur+1) - '0'));
                break;
            default:
                break;
        }

        ++cur;

    }
    return 0;
}

int process_token(char *op) {return 0;}

