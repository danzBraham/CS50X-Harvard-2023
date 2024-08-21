#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(const char *prompt);
int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);
double calculate_index(int letters, int words, int senteces);
void print_grade_level(double index);

int main(void)
{
  // Prompt the user for some text
  char *text = get_string("Text: ");

  // Count the number of letters, words, and sentences.
  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  // Calculate the Coleman-Liau index
  double index = calculate_index(letters, words, sentences);

  // Print the grade level
  print_grade_level(index);

  free(text);
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

int count_letters(char *text)
{
  int letters = 0;

  for (int i = 0, len = strlen(text); i < len; i++)
  {
    if (isalnum(text[i]))
    {
      letters++;
    }
  }

  return letters;
}

int count_words(char *text)
{
  int words = 0;
  int len = strlen(text);
  bool in_word = false;

  for (int i = 0; i < len; i++)
  {
    if (isalnum(text[i]) || text[i] == '\'' || text[i] == '-')
    {
      if (!in_word)
      {
        words++;
        in_word = true;
      }
    }
    else
    {
      in_word = false;
    }
  }

  return words;
}

int count_sentences(char *text)
{
  int sentences = 0;
  int len = strlen(text);

  for (int i = 0; i < len; i++)
  {
    if (text[i] == '.' || text[i] == '?' || text[i] == '!')
    {
      sentences++;
    }
  }

  return sentences;
}

double calculate_index(int letters, int words, int senteces)
{
  double L = ((double)letters / words) * 100;
  double S = ((double)senteces / words) * 100;
  return 0.0588 * L - 0.296 * S - 15.8;
}

void print_grade_level(double index)
{
  int rounded = round(index);

  if (rounded < 1)
  {
    printf("Before Grade 1\n");
    return;
  }

  if (rounded >= 16)
  {
    printf("Grade 16+\n");
    return;
  }

  printf("Grade %i\n", rounded);
  return;
}
