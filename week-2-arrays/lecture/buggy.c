#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(const char *prompt);
void print_column(int height);

int main(void)
{
  int h = get_int("Height: ");
  if (h == -1)
  {
    fprintf(stderr, "Failed to get input.\n");
    return 1;
  }

  print_column(h);
  return 0;
}

int get_int(const char *prompt)
{
  char buffer[5];
  char *endptr;
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
      buffer[len - 1] = '\0';
    }
    else
    {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    int is_valid = 1;
    for (int i = 0; buffer[i]; i++)
    {
      if (!isdigit(buffer[i]))
      {
        is_valid = 0;
        break;
      }
    }

    if (!is_valid)
    {
      continue;
    }

    number = (int)strtol(buffer, &endptr, 10);

    if (*endptr == '\0' && number > 0)
    {
      return number;
    }
  }
}

void print_column(int height)
{
  for (int i = 0; i <= height; i++)
  {
    printf("#\n");
  }
}