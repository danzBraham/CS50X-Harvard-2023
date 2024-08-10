#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  char *name = get_string("What's your name? ");
  printf("Hello, %s!\n", name);
  free(name);
  return 0;
}

char *get_string(const char *prompt)
{
  int string_size = 255 * sizeof(char);
  printf("%s", prompt);

  char *str = malloc(string_size);
  if (str == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  fgets(str, string_size, stdin);
  str[strcspn(str, "\n")] = '\0';

  return str;
}