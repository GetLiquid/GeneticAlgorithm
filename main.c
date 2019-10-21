#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "tree.h"
#include "util.h"
#include "critter.h"

float fitness(char *genome);
float sum_tree(struct node *root);

int main()
{
    srand(time(NULL)*getpid());

    for(int i=0;i<50;++i)
    {
        struct critter * a = new_critter();
        print_critter(a);
        
        printf("%s\n", process_gene(a->gene));
    }

    return 0;
}
