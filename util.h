#pragma once
#include <stdint.h>
#include "critter.h"

//Generic helper functions
int is_number(char);
int is_operator(char);
void print_bitset(uint64_t);
int str_length(const char*);

//Fitness function
float fitness(uint64_t gene);

//Node data type for expression tree
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

//Declarations of expression tree-related functions
float sum_tree(struct node*);
int operator_comes_after(char, char);
void print_tree(struct node *);
void print_tree_layer(struct node *, int);
struct node *build_tree(char*, int, int);

//Helper functions for struct critter
struct critter *copy_critter(struct critter *from);
void exchange_critter(struct critter* A, struct critter* B);

//Declarations for sorting functions
int partition(struct critter*  A, int low, int high);
void quicksort(struct critter* A, int low, int high);
