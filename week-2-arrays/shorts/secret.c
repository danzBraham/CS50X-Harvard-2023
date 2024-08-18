#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);
bool check_phrase(char *phrase);

int main(void)
{
  char *phrase = get_string("What's the secret phrase? ");
  if (phrase == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  if (!check_phrase(phrase))
  {
    printf("Not Allowed!\n");
    return 1;
  }

  printf("Come on in!\n");
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = sizeof(char) * 100;
  char *str = malloc(STRING_SIZE);
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
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

    char *tmp = realloc(str, strlen(str) + 1);
    if (tmp != NULL)
    {
      str = tmp;
    }

    return str;
  }
}

bool check_phrase(char *phrase)
{
  return (strcmp(phrase, "please") == 0);
}