// Implements Linear Search
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);

int main(void)
{
  char *fruits[] = {"banana", "durian", "apple", "watermelon"};

  char *fruit = get_string("Fruit: ");
  if (fruit == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  for (int i = 0; i < 4; i++)
  {
    if (strcmp(fruits[i], fruit) == 0)
    {
      printf("The fruit found\n");
      free(fruit);
      return 0;
    }
  }

  printf("The fruit not found\n");
  free(fruit);
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