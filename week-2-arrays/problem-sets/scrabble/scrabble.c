#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

char *get_string(const char *prompt);
int calculate_score(char *word);
void print_winner(int score_player_one, int score_player_two);

int main(void)
{
  char *player_one = get_string("Player 1: ");
  if (player_one == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  char *player_two = get_string("Player 2: ");
  if (player_two == NULL)
  {
    fprintf(stderr, "Failed to get input\n");
    return 1;
  }

  int score_player_one = calculate_score(player_one);
  int score_player_two = calculate_score(player_two);

  print_winner(score_player_one, score_player_two);

  free(player_one);
  free(player_two);
  return 0;
}

char *get_string(const char *prompt)
{
  const int STRING_SIZE = sizeof(char) * 100;
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

    size_t len = strlen(str);
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

int calculate_score(char *word)
{
  int score = 0;

  for (int i = 0, len = strlen(word); i < len; i++)
  {
    if (!isalpha(word[i]))
    {
      continue;
    }
    score += point[toupper(word[i]) - 'A'];
  }

  return score;
}

void print_winner(int score_player_one, int score_player_two)
{
  if (score_player_one > score_player_two)
  {
    printf("Player 1 wins!\n");
    return;
  }

  if (score_player_one < score_player_two)
  {
    printf("Player 2 wins!\n");
    return;
  }

  printf("Tie!\n");
  return;
}