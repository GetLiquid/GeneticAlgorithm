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

void exchange_critter(struct critter *A, struct critter *B)
{
    struct critter temp;
    temp.id = A->id;
    temp.gene = A->gene;

    A->id = B->id;
    A->gene = B->gene;

    B->id = temp.id;
    B->gene = temp.gene;
}

struct critter * copy_critter(struct critter *from)
{
    struct critter * to = malloc(sizeof(struct critter));
    to->id = from->id;
    to->gene = from->gene;
    return to;
}

int partition(struct critter *A, int low, int high)
{
    struct critter *x = copy_critter(A+high);
    int i = low - 1;
    for(int j=low;j<high-1;++j)
    {
        if(A[i].gene < x->gene)
        {
            ++i;
            //exchange A[i] and A[j]
            exchange_critter(A+i, A+j);
        }
    }
    //exchange A[i+1] and A[high]
    exchange_critter(A+i+1, A+high);
    return i+1;
}

void quicksort(struct critter *A, int low, int high)
{
    if(low < high)
    {
        int mid = partition(A, low, high);
        quicksort(A, low, mid - 1);
        quicksort(A, mid + 1, high);
    }
}
