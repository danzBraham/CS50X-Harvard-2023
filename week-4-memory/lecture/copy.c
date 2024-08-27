#include <ctype.h>
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

  char *t = malloc(strlen(s) + 1);
  if (t == NULL)
  {
    return 1;
  }

  // Imperative approach
  // for (int i = 0, n = strlen(s); i <= n; i++)
  // {
  //   t[i] = s[i];
  // }

  // Declarative approach
  strcpy(t, s);

  if (strlen(t) > 0)
  {
    t[0] = toupper(t[0]);
  }

  printf("%s\n", s);
  printf("%s\n", t);

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