#include <stdio.h>

int sum(int a, int b);

int main(void)
{
  int x, y;

  printf("X: ");
  scanf("%i", &x);
  printf("Y: ");
  scanf("%i", &y);

  printf("Total: %i\n", sum(x, y));
  return 0;
}

int sum(int a, int b)
{
  return a + b;
}