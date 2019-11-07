#include "critter.h"
#include "util.h"


void merge(struct critter *A, int low, int mid, int high, int length)
{
    int l1,l2,i;
    struct critter temp[length];

    for(l1=low,l2=mid+1,i=low;l1 <= mid && l2 <= high; ++i)
    {
        if(fitness(A[l1].gene) > fitness(A[l2].gene))
            temp[i] = A[l1++];
        else
            temp[i] = A[l2++];
    }

    while(l1 <= mid)
        temp[i++] = A[l1++];
    while(l2 <= high)
        temp[i++] = A[l2++];
    for(i=low;i<=high;++i)
        A[i] = temp[i];
}

void merge_sort(struct critter *A, int low, int high, int length)
{
    if(low < high)
    {
        int mid = (low+high) / 2;
        merge_sort(A, low, mid, length);
        merge_sort(A, mid+1, high, length);
        merge(A, low, mid, high, length);
    }
}
