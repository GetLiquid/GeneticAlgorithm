#include "critter.h"
#include <stdlib.h>
#include <stdio.h>
#include "util.h"

struct critter * new_critter()
{
    struct critter *out = malloc(sizeof(struct critter));

    out->id = 'A' +  (rand()%52);
    out->gene = rand();
    out->gene |= (uint64_t)rand() << 32;

    return out;
}

struct critter * crossover(struct critter *a, struct critter *b)
{
    struct critter *c = malloc(sizeof(struct critter));
    
    
    c->id = 'A' + (rand()%52);

    c->gene = a->gene;
    uint64_t swap_index = 0xFFFFFFFFFFFFFFFF >> (rand()%64);
    uint8_t flip = rand()%2;
    if(flip)
        swap_index = ~swap_index;
    
    c->gene &= swap_index;
    c->gene |= (~swap_index & b->gene);

    return c;
}

void print_critter(struct critter *crit)
{
    printf("Critter %c: ", crit->id);
    print_bitset(crit->gene);
    printf("\n");
}
