#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  char *name = get_string("What's your name? ");
  if (name == NULL)
  {
    fprintf(stderr, "Failed to get input.\n");
    return 1;
  }

  printf("Hello, %s\n", name);

  free(name);
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = 255 * sizeof(char);
  printf("%s", prompt);

  char *str = malloc(STRING_SIZE);
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
    return NULL;
  }

  if (fgets(str, STRING_SIZE, stdin) == NULL)
  {
    free(str);
    return NULL;
  }

  str[strcspn(str, "\n")] = '\0';

  return str;
}
