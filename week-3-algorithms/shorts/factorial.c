#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n);

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

  printf("%i\n", fact(number));

  return 0;
}

int fact(int n)
{
  // base case
  if (n <= 1)
  {
    return 1;
  }

  // recursive case
  return n * fact(n - 1);
}
