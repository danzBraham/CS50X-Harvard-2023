#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./cat textfile\n");
    return 1;
  }

  FILE *textfile = fopen(argv[1], "r");
  if (textfile == NULL)
  {
    printf("File not found\n");
    return 2;
  }

  char c;
  while ((c = fgetc(textfile)) != EOF)
  {
    printf("%c", c);
  }

  fclose(textfile);
  return 0;
}