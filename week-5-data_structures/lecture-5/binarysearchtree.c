#include <stdio.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

int search(node *tree, int number)
{
    if (tree == NULL)
        return 0;

    if (number < tree->number)
        return search(tree->left, number);
    else if (number > tree->number)
        return search(tree->right, number);
    else
        return 1;
}

int main(void)
{

}