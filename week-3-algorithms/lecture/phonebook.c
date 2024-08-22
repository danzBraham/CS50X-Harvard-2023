// Implements Structs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *name;
  char *number;
} person;

char *get_string(const char *prompt);

int main(void)
{
  person people[3];

  people[0].name = "Zidan";
  people[0].number = "081234567894";

  people[1].name = "Abra";
  people[1].number = "081234523341";

  people[2].name = "John";
  people[2].number = "089465271884";

  char *name = get_string("Name: ");
  if (name == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  for (int i = 0; i < 3; i++)
  {
    if (strcmp(people[i].name, name) == 0)
    {
      printf("Found %s\n", people[i].number);
      free(name);
      return 0;
    }
  }

  printf("Not found\n");
  free(name);
  return 1;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = sizeof(char) * 20;
  char *str = malloc(STRING_SIZE);
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
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