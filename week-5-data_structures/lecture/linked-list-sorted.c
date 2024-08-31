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
    // If number belongs beginning of list
    else if (n->number < list->number)
    {
      n->next = list;
      list = n;
    }
    // If number belongs later of list
    else
    {
      for (node *ptr = list; ptr != NULL; ptr = ptr->next)
      {
        // If at the end of the list
        if (ptr->next == NULL)
        {
          // Append mode
          ptr->next = n;
          break;
        }

        // If ins the middle of the list
        if (n->number < ptr->next->number)
        {
          n->next = ptr->next;
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
