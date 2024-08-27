#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  // Open file in append mode
  FILE *file = fopen("phonebook.csv", "a");
  if (!file)
  {
    return 1;
  }

  char *name = get_string("Name: ");
  if (!name)
  {
    return 2;
  }

  char *number = get_string("Number: ");
  if (!number)
  {
    return 3;
  }

  // Print to file
  fprintf(file, "%s,%s\n", name, number);

  free(name);
  free(number);

  // Close the file
  fclose(file);

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