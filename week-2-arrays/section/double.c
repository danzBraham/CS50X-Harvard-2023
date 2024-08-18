#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(const char *prompt);

int main(void)
{
  int size = get_int("Size: ");
  int sequence[size];
  sequence[0] = 1;
  printf("%i\n", sequence[0]);

  for (int i = 1; i < size; i++)
  {
    sequence[i] = sequence[i - 1] * 2;
    printf("%i\n", sequence[i]);
  }

  return 0;
}

int get_int(const char *prompt)
{
  char buffer[100];
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    size_t len = strlen(buffer);
    if (len <= 1)
    {
      continue;
    }

    if (buffer[len - 1] == '\n')
    {
      buffer[len - 1] = '\0';
    }
    else
    {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    bool is_valid = true;
    for (int i = 0; buffer[i]; i++)
    {
      if (!isdigit(buffer[i]))
      {
        is_valid = false;
        break;
      }
    }

    if (!is_valid)
    {
      continue;
    }

    number = atoi(buffer);
    ;

    if (number > 0)
    {
      return number;
    }
  }
}