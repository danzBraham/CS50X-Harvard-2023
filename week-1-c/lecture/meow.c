#include <stdio.h>

void meow(int n);

int main(void)
{
  int x;

  printf("How many meow do u want to hear? ");
  scanf("%i", &x);

  meow(x);
  return 0;
}

void meow(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("meow\n");
  }
}