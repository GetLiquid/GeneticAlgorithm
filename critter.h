#include <stdint.h>

struct critter
{
    char id;
    uint64_t gene;
};

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node * get_last_operator(char *array, int low, int high);

void print_critter(struct critter *);
struct critter * crossover(struct critter*, struct critter*);
struct critter * new_critter();
char * process_gene(struct critter *);

void  print_bitset(uint64_t);
uint8_t is_number(char);
uint8_t is_operator(char);
