#include "critter.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t is_number(char c)
{
    return c >= '0' && c <= '9';
}

uint8_t is_operator(char c)
{
    return (c == '+') || (c == '-') || (c == 'x') || (c == '/');
}

void print_bitset(uint64_t in)
{
    for(int i=0;i<sizeof(in)*2;++i)
    {
        uint8_t temp = (uint8_t) (in >> i*4) & 0xF;
        for(int i=3;i>=0;--i)
        {
            if(1 & (temp >> i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}

char * process_gene(struct critter * in)
{
    if(!in)
        return NULL;

    int num_chars = sizeof(in->gene)*2;
    char *raw_gene = malloc(num_chars+1);
    for(int i=0;i<num_chars+1;++i)
    {
        raw_gene[i] = 0;
    }
    
    uint64_t temp_genome = in->gene;

    char curr_char = '\0';
    char *raw_char = raw_gene;
    char prev_char = '+';
    for(int i=0;i<num_chars;++i)
    {
        uint8_t cur_raw_int = (temp_genome >> i*4) & 0x0F;

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

int gene_length(const char *input)
{
    int count = 0;
    while(*(input + count))
        ++count;
    return count;
}


int op_comes_after(char a, char b) //returns 1 if b comes after a
{
    /*if(b == '-')
        return 1;
    */
    if(!is_operator(a))
        return 1;
    if(a == '*')
      a = '/';
    if(b == '*')
      b = '/';

    char operators[] = {'*', '/', '+', '-'};
    int a_index = 0;
    int b_index = 0;
    for(int i=0;i<4;++i)
    {
        if(a == operators[i])
            a_index = i;
        if(b == operators[i])
            b_index = i;
    }
    return b_index > a_index;
}

