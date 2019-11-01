#include "util.h"
#include "critter.h"

// Quicksort implementation
int partition(struct critter *A, int low, int high)
{
    struct critter *x = copy_critter(A+high);
    int i = low - 1;
    for(int j=low;j<high-1;++j)
    {
        if(fitness(A[i].gene) < fitness(x->gene))
        {
            ++i;
            exchange_critter(A+i, A+j);
        }
    }
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
