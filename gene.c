#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "critter.h"
#include "util.h"

int fitness(char *genome);

int main()
{
    srand(time(NULL)*getpid());

    struct critter * crit_one = new_critter();
    struct critter * crit_two = new_critter();

    struct critter * crit_three = crossover(crit_one, crit_two);
    print_critter(crit_three);
    printf("%s\n", process_gene(crit_three));
    fitness(process_gene(crit_three));
    printf("\n");

    return 0;
}

void print_tree(struct node *root)
{
  if(!root)
    return;

  printf("Node: %c\n", root->data);
  print_tree(root->left);
  print_tree(root->right);

}

int sum_tree(struct node *root)
{
  if(!root)
    return 0;

  if(!(root->left) && !(root->right))
    return root->data - '0';

  if(root->left && root->right)
  {
    switch(root->data)
    {
      case '+':
        printf("Add: ");
        return sum_tree(root->left) + sum_tree(root->right);
      case '-':
        printf("Subtract: ");
        return sum_tree(root->left) - sum_tree(root->right);
      case '*':
        printf("Mult: ");
        return sum_tree(root->left) * sum_tree(root->right);
      case '/':
        printf("Div: ");
        return sum_tree(root->left) / sum_tree(root->right);
      default:
        return 0;
    }
  }

}

int fitness(char *genome)
{
    struct node *root = get_last_operator(genome, 0, gene_length(genome)-1);
    //print_tree(root);
    printf("Sum: %d\n", sum_tree(root));
    return 0;
}
