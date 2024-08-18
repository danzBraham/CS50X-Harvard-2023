#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  char *phrase = get_string("Enter a phrase: ");
  if (phrase == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  for (int i = 0, len = strlen(phrase); i < len - 1; i++)
  {
    if (toupper(phrase[i]) > toupper(phrase[i + 1]))
    {
      printf("Phrase \"%s\" is not in alphabetical order\n", phrase);
      free(phrase);
      return 0;
    }
  }

  printf("Phrase \"%s\" is in alphabetical order\n", phrase);
  free(phrase);
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = sizeof(char) * 25;
  char *str = malloc(STRING_SIZE);
  if (str == NULL)
  {
    fprintf(stderr, "Memory alloction failed\n");
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

    char *tmp = realloc(str, len + 1);
    if (tmp != NULL)
    {
      str = tmp;
    }

    return str;
  }
}