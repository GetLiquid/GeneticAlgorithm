#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "critter.h"
#include "tree.h"

#ifndef CRITTER
#define CRITTER
#endif

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
    if(!crit)
      return;

    printf("Critter %c: ", crit->id);
    print_bitset(crit->gene);
    printf("\n");
}

char * process_gene(uint64_t bitset)
{
    int num_chars = sizeof(bitset)*2;
    char *raw_gene = malloc(num_chars+1);
    for(int i=0;i<num_chars+1;++i)
    {
        raw_gene[i] = 0;
    }
    
    char curr_char = '\0';
    char *raw_char = raw_gene;
    char prev_char = '+';
    for(int i=0;i<num_chars;++i)
    {
        uint8_t cur_raw_int = (bitset >> i*4) & 0x0F;

        if(cur_raw_int < 0xA)
        {
            curr_char = cur_raw_int + '0';
        }
        else if(cur_raw_int < 0xE)
        {
            switch(cur_raw_int)
            {
                case 0xA:
                    curr_char = '+';
                    break;
                case 0xB:
                    curr_char = '-';
                    break;
                case 0xC:
                    curr_char = 'x';
                    break;
                case 0xD:
                    curr_char = '/';
                    break;
                default:
                    break;
            }
        } else
            curr_char = '.';

        if((is_number(curr_char) && is_operator(prev_char)) || (is_operator(curr_char) && is_number(prev_char)))
        {
            *raw_char = curr_char;
            ++raw_char;
            prev_char = curr_char;

        }

    }
    return raw_gene;
}

float sum_gene(char *genome)
{
    struct node *root = build_tree(genome, 0, str_length(genome)-1);
    //print_tree(root);
    return sum_tree(root);
}
