#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 255

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
  char *str = malloc(MAX_LENGTH * sizeof(char));
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed.\n");
    return NULL;
  }

  printf("%s", prompt);

  if (fgets(str, MAX_LENGTH, stdin) == NULL)
  {
    free(str);
    return NULL;
  }

  size_t len = strlen(str);
  if (len > 0 && str[len - 1] == '\n')
  {
    str[len - 1] = '\0';
  }
  else
  {
    // Clear input buffer if input is too long
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }

  return str;
}
