#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

char *get_string(const char *prompt);

int main(void)
{
  char *s = get_string("Before: ");
  printf("After:  ");

  // Manual
  // for (int i = 0; i < strlen(s); i++)
  // {
  //     if (s[i] >= 'a' && s[i] <= 'z')
  //     {
  //         printf("%c", s[i] - 32);
  //     }
  //     else
  //     {
  //         printf("%c", s[i]);
  //     }
  // }

  // Using ctype library
  for (int i = 0, n = strlen(s); i < n; i++)
  {
    printf("%c", toupper(s[i]));
  }

  printf("\n");
}

char *get_string(const char *prompt)
{
  char *str = malloc(sizeof(char) * MAX_LENGTH);
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
    return NULL;
  }

  while (1)
  {
    printf("%s", prompt);
    if (fgets(str, MAX_LENGTH, stdin) == NULL)
    {
      free(str);
      return NULL;
    }

    size_t len = strlen(str);
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

    // Trim excess memory
    char *tmp = realloc(str, len + 1);
    if (tmp != NULL)
    {
      str = tmp;
    }

    return str;
  }
}
