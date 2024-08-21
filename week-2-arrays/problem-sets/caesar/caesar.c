#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);
void caesar(char *plaintext, int key);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  char *key_str = argv[1];

  for (int i = 0, len = strlen(key_str); i < len; i++)
  {
    if (!isdigit(key_str[i]))
    {
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }

  int key = atoi(key_str);

  char *plaintext = get_string("plaintext:  ");
  if (plaintext == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
  }

  caesar(plaintext, key);

  free(plaintext);
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = sizeof(char) * (1000);
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

void caesar(char *plaintext, int key)
{
  int plaintext_len = strlen(plaintext);
  char ciphertext[plaintext_len + 1];

  ciphertext[plaintext_len] = '\0';

  key %= 26;

  for (int i = 0; i < plaintext_len; i++)
  {
    char c = plaintext[i];

    if (isalpha(c))
    {
      char base = isupper(c) ? 'A' : 'a';
      ciphertext[i] = (c - base + key) % 26 + base;
    }
    else
    {
      ciphertext[i] = c;
    }
  }

  printf("ciphertext: %s\n", ciphertext);
}