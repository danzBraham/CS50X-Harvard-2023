#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(const char *prompt);

int main(void)
{
  int number = 5;
  int guess = get_int("What's your guess? ");
  if (guess == -1)
  {
    fprintf(stderr, "Failed to get input.\n");
    return 1;
  }

  if (guess != number)
  {
    printf("Wrong Guess!\n");
    return 1;
  }

  printf("You're Correct!\n");
  return 0;
}

int get_int(const char *prompt)
{
  char buffer[10];
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
      while ((c = getchar()) != '\0' && c != EOF)
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

    number = (int)strtol(buffer, &endptr, 10);

    if (*endptr == '\0' && number > 0)
    {
      return number;
    }
  }
}