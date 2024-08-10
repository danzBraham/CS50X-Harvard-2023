#include <stdio.h>
#include <stdlib.h>

int *get_int(const char *prompt);
void print_row(int length);

int main(void)
{
  int *height = get_int("Height: ");

  for (int i = 0; i < *height; i++)
  {
    print_row(i + 1);
  }
  free(height);
  return 0;
}

int *get_int(const char *prompt)
{
  int *n = malloc(sizeof(int));
  if (n == NULL)
  {
    printf("Memory allocation failed.");
    return 0;
  }

  printf("%s", prompt);
  scanf("%i", n);

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }

  return n;
}

void print_row(int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("#");
  }
  printf("\n");
}