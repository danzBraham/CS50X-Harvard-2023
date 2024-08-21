#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);
void substitution(char *plaintext, char *key);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./substitution key\n");
    return 1;
  }

  char *key = argv[1];
  int key_len = strlen(argv[1]);

  if (key_len < 26)
  {
    printf("Key must contain 26 characters\n");
    return 1;
  }

  for (int i = 0; i < key_len; i++)
  {
    if (!isalpha(key[i]))
    {
      printf("Key must alphabet\n");
      return 1;
    }

    for (int j = 0; j < key_len; j++)
    {
      if (i == j)
      {
        continue;
      }
      if (key[i] == key[j])
      {
        printf("Key must not have a duplicate alphabet\n");
        return 1;
      }
    }
  }

  char *plaintext = get_string("plaintext:  ");
  if (plaintext == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  substitution(plaintext, key);

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

void substitution(char *plaintext, char *key)
{
  int plaintext_len = strlen(plaintext);
  char ciphertext[plaintext_len + 1];

  ciphertext[plaintext_len] = '\0';

  for (int i = 0; i < plaintext_len; i++)
  {
    char plainchar = plaintext[i];
    if (isalpha(plainchar))
    {
      ciphertext[i] = isupper(plainchar) ? toupper(key[plainchar - 'A']) : tolower(key[plainchar - 'a']);
    }
    else
    {
      ciphertext[i] = plainchar;
    }
  }

  printf("ciphertext: %s\n", ciphertext);
}
