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
