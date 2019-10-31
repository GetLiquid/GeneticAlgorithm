#pragma once
#include <stdint.h>
#include "critter.h"

int is_number(char);
int is_operator(char);
void print_bitset(uint64_t);
int str_length(const char*);

//Declarations for tree-related functions
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

float sum_tree(struct node*);
int operator_comes_after(char, char);

void print_tree(struct node *);
void print_tree_layer(struct node *, int);
struct node *build_tree(char*, int, int);

//Declarations for sorting functions
int partition(struct critter*  A, int low, int high);
void quicksort(struct critter* A, int low, int high);
