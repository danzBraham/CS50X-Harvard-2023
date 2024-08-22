#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(stderr, "Usage: ./factorial number\n");
    return 1;
  }

  char *arg = argv[1];

  for (int i = 0, len = strlen(arg); i < len; i++)
  {
    if (!isdigit(arg[i]))
    {
      fprintf(stderr, "Usage: ./factorial number\n");
      return 1;
    }
  }

  int number = atoi(arg);

  printf("%i\n", factorial(number));

  return 0;
}

int factorial(int n)
{
  // base case
  if (n <= 1)
  {
    return 1;
  }

  // recursive case
  return n * factorial(n - 1);
}
