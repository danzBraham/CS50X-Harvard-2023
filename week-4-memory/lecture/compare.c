#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  char *s = get_string("s: ");
  if (s == NULL)
  {
    return 1;
  }

  char *t = get_string("t: ");
  if (t == NULL)
  {
    return 1;
  }

  // You can't do this cause it'll compare the addresses not the actual string
  s == t ? printf("Same\n") : printf("Different\n");
  printf("%p\n", s);
  printf("%p\n", t);

  // Instead you must do this when comparing string
  strcmp(s, t) == 0 ? printf("Same\n") : printf("Different\n");

  free(s);
  free(t);
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = 100;
  char *str = malloc(sizeof(char) * STRING_SIZE);
  if (str == NULL)
  {
    return NULL;
  }

  while (1)
  {
    printf("%s", prompt);
    if (fgets(str, STRING_SIZE, stdin) == NULL)
    {
      free(str);
      return NULL;
    }

    int len = strlen(str);
    if (len <= 1)
    {
      continue;
    }

    if (str[len - 1] == '\n')
    {
      str[len - 1] = '\0';
    }
    else
    {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    char *tmp = realloc(str, len + 1);
    if (tmp != NULL)
    {
      str = tmp;
    }

    return str;
  }
}