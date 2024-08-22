#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(const char *prompt);
void draw(int n);

int main(void)
{
  int height = get_int("Height: ");
  if (height == -1)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  draw(height);
  return 0;
}

int get_int(const char *prompt)
{
  char buffer[10];
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    int len = strlen(buffer);
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

    if (number <= 0)
    {
      continue;
    }

    return number;
  }
}

void draw(int n)
{
  if (n <= 0)
  {
    return;
  }

  draw(n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("#");
  }
  printf("\n");
}
