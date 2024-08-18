#include <stdio.h>

int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("argv[%i] is %s\n", i, argv[i]);
  }
}