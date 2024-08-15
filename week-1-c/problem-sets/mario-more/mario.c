#include <stdio.h>
#include <stdlib.h>

int *get_int(const char *prompt);

int main(void)
{
  int *height = get_int("Height: ");
  if (height == NULL)
  {
    fprintf(stderr, "Failed to get input.\n");
    return 1;
  }

  for (int i = 0; i < *height; i++)
  {
    for (int j = *height; j > i + 1; j--)
    {
      printf(" ");
    }

    for (int k = 0; k < i + 1; k++)
    {
      printf("#");
    }

    printf("  ");

    for (int l = 0; l < i + 1; l++)
    {
      printf("#");
    }

    printf("\n");
  }

  free(height);
  return 0;
}

int *get_int(const char *prompt)
{
  int *integer = malloc(sizeof(int));
  if (integer == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
    return NULL;
  }

  do
  {
    printf("%s", prompt);
    scanf("%i", integer);
  } while (*integer < 1 || *integer > 8);

  return integer;
}