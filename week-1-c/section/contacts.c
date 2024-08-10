#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);
int *get_int(const char *prompt);

int main(void)
{
  char *name = get_string("What's your name? ");
  int *age = get_int("What's your age? ");
  char *phone_number = get_string("What's your phone number? ");

  printf("========================================\n");
  printf("Name: %s\n", name);
  printf("Age: %i\n", *age);
  printf("Phone Number: %s\n", phone_number);

  free(name);
  free(age);
  free(phone_number);

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

int *get_int(const char *prompt)
{
  int *i = malloc(sizeof(int));
  if (i == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  printf("%s", prompt);
  scanf("%i", i);

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }

  return i;
}