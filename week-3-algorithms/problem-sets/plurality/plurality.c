#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
  char *name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
char *get_string(const char *prompt);
int get_int(const char *prompt);
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX)
  {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
  }

  int voter_count = get_int("Number of voters: ");

  // Loop over all voters
  for (int i = 0; i < voter_count; i++)
  {
    char *name = get_string("Vote: ");

    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }

    free(name);
  }

  // Display winner of election
  print_winner();
  return 0;
}

// Get input string
char *get_string(const char *prompt)
{
  const int STRING_SIZE = 50;
  char *str = malloc(sizeof(char) * STRING_SIZE);
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

// Get int input
int get_int(const char *prompt)
{
  char buffer[100];
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    int len = strlen(buffer);
    if (len <= 1)
    {
      continue;
    }

    if (buffer[len - 1] == '\n')
    {
      buffer[len - 1] = '\0';
    }
    else
    {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

    bool is_valid = true;
    for (int i = 0; buffer[i]; i++)
    {
      if (!isdigit(buffer[i]))
      {
        is_valid = false;
        break;
      }
    }

    if (!is_valid)
    {
      continue;
    }

    number = atoi(buffer);

    if (number > 0)
    {
      return number;
    }
  }
}

// Update vote totals given a new vote
bool vote(char *name)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(name, candidates[i].name) == 0)
    {
      candidates[i].votes++;
      return true;
    }
  }
  return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  // TODO
  int highest_votes = 0;

  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes > highest_votes)
    {
      highest_votes = candidates[i].votes;
    }
  }

  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes == highest_votes)
    {
      printf("%s\n", candidates[i].name);
    }
  }

  return;
}