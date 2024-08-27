#include <stdio.h>

int main(void)
{
  int garbages[1024];
  for (int i = 0; i < 1024; i++)
  {
    printf("%i\n", garbages[i]);
  }
  return 0;
}