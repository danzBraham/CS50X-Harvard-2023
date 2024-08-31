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

    n->number = number;
    n->next = NULL;

    // If list is empty
    if (list == NULL)
    {
      list = n;
    }
    else
    {
      for (node *ptr = list; ptr != NULL; ptr = ptr->next)
      {
        // At the end of the list
        if (ptr->next == NULL)
        {
          ptr->next = n;
          break;
        }
      }
    }
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