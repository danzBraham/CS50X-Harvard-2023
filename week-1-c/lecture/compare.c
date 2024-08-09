#include <stdio.h>

int main(void)
{
  int x, y;

  printf("What's x? ");
  scanf("%i", &x);
  printf("What's y? ");
  scanf("%i", &y);

  if (x < y)
  {
    printf("x is less than y\n");
  }
  else if (x > y)
  {
    printf("x is greater than y\n");
  }
  else
  {
    printf("x is equal to y\n");
  }

  return 0;
}