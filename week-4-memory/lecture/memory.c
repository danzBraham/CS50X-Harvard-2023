#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int *x = malloc(sizeof(int) * 3);
  x[0] = 72;
  x[1] = 73;
  x[2] = 33;

  free(x);
  return 0;
}