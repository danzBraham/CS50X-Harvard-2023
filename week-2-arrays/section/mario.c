#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./mario number\n");
    return 1;
  }

  char *arg = argv[1];
  for (int i = 0; arg[i]; i++)
  {
    if (!isdigit(arg[i]))
    {
      printf("The argument is not a valid number\n");
      return 1;
    }
  }

  int n = atoi(argv[1]);
  for (int i = 0; i < n; i++)
  {
    printf("#\n");
  }

  return 0;
}