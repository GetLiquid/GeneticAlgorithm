#pragma once
#include <stdint.h>
#include "critter.h"

//Generic helper functions
int is_number(char);           //returns 1 if char input is a numeric
int is_operator(char);         //returns 1 if the char input is '+', '-', '*' or '/'
void print_bitset(uint64_t);   //prints a 64 bit set in binary 4-bit chunks 
int str_length(const char*);   //returns the length of a c-style string

//Fitness function
float fitness(uint64_t gene);
float fitness_char(char *gene);

//Node data type for expression tree
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

//Declarations of expression tree-related functions
float sum_tree(struct node*);                   //Computes the sum of the an expression tree
int operator_comes_after(char A, char B);       //Returns 1 if B comes after A
void print_tree(struct node * tree);            //Prints all nodes in the provided tree
void print_tree_layer(struct node *tree, int);  //Prints the layer
struct node *build_tree(char*, int, int);       //Builds an expression tree from an array of characters

//Helper functions for struct critter
struct critter *copy_critter(struct critter *from);
void exchange_critter(struct critter* A, struct critter* B);

//Declarations for sorting functions
void merge(struct critter **A, int low, int mid, int high, int length);
void merge_sort(struct critter **A, int low, int high, int length);
