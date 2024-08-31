#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int number;
  struct node *next;
} node;

int main(int argc, char *argv[])
{
  node *list = NULL;

  for (int i = 0; i < argc; i++)
  {
    int number = atoi(argv[i]);

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
      return 1;
    }

    // (*n).number = number; -> This syntax
    n->number = number; // Equal to this syntax
    n->next = NULL;

    // Prepend node to list
    n->next = list;
    list = n;
  }

  // Print numbers
  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%i\n", ptr->number);
  }

  // Free memory
  node *ptr = list;
  while (ptr != NULL)
  {
    node *next = ptr->next;
    free(ptr);
    ptr = next;
  }

  return 0;
}