#include <stdio.h>

void block(int n);

int main(void)
{
  int x, valid_input;

  // Prompt user for positive integer
  do
  {
    printf("Size: ");
    valid_input = scanf("%i", &x);

    if (valid_input != 1)
    {
      while (getchar() != '\n')
        ;
    }
  } while (x < 1 || valid_input != 1);

  // Print an n-by-n grid of blocks
  block(x);
  return 0;
}

void block(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}