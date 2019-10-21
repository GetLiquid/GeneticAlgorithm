#include "critter.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int is_number(char c)
{
    return c >= '0' && c <= '9';
}

int is_operator(char c)
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

int str_length(const char *input)
{
    int count = 0;
    while(*(input + count))
        ++count;
    return count;
}


