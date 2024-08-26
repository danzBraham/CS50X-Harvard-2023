#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
  char *name;
  int votes;
  bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
char *get_string(const char *format, ...);
int get_int(const char *prompt);
bool vote(int voter, int rank, char *name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: runoff [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX_CANDIDATES)
  {
    printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
    candidates[i].eliminated = false;
  }

  voter_count = get_int("Number of voters: ");
  if (voter_count > MAX_VOTERS)
  {
    printf("Maximum number of voters is %i\n", MAX_VOTERS);
    return 3;
  }

  // Keep querying for votes
  for (int i = 0; i < voter_count; i++)
  {
    // Query for each rank
    for (int j = 0; j < candidate_count; j++)
    {
      char *name = get_string("Rank %i: ", j + 1);

      // Record vote, unless it's invalid
      if (!vote(i, j, name))
      {
        printf("Invalid vote.\n");
        return 4;
      }

      free(name);
    }

    printf("\n");
  }

  // Keep holding runoffs until winner exists
  while (true)
  {
    // Calculate votes given remaining candidates
    tabulate();

    // Check if election has been won
    bool won = print_winner();
    if (won)
    {
      break;
    }

    // Eliminate last-place candidates
    int min = find_min();
    bool tie = is_tie(min);

    // If tie, everyone wins
    if (tie)
    {
      for (int i = 0; i < candidate_count; i++)
      {
        if (!candidates[i].eliminated)
        {
          printf("%s\n", candidates[i].name);
        }
      }
      break;
    }

    // Eliminate anyone with minimum number of votes
    eliminate(min);

    // Reset vote counts back to zero
    for (int i = 0; i < candidate_count; i++)
    {
      candidates[i].votes = 0;
    }
  }

  return 0;
}

// Get input string
char *get_string(const char *format, ...)
{
  const int STRING_SIZE = 50;
  char *str = malloc(sizeof(char) * STRING_SIZE);
  if (str == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  // Handling variable arguments
  const int PROMPT_SIZE = 256;
  char prompt[PROMPT_SIZE];
  va_list args;

  va_start(args, format);
  vsnprintf(prompt, PROMPT_SIZE, format, args);
  va_end(args);

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

// Record preference if vote is valid
bool vote(int voter, int rank, char *name)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(candidates[i].name, name) == 0)
    {
      preferences[voter][rank] = i;
      return true;
    }
  }
  return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
  // TODO
  for (int i = 0; i < voter_count; i++)
  {
    for (int j = 0; j < candidate_count; j++)
    {
      if (!candidates[preferences[i][j]].eliminated)
      {
        candidates[preferences[i][j]].votes++;
        break;
      }
    }
  }
  return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
  // TODO
  int half_votes = voter_count / 2;
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].votes > half_votes)
    {
      printf("%s\n", candidates[i].name);
      return true;
    }
  }
  return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
  // TODO
  int min = voter_count;
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].eliminated)
    {
      continue;
    }
    if (candidates[i].votes < min)
    {
      min = candidates[i].votes;
    }
  }
  return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
  // TODO
  bool is_tied = false;
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].eliminated)
    {
      continue;
    }
    is_tied = candidates[i].votes == min;
  }
  return is_tied;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (candidates[i].eliminated)
    {
      continue;
    }
    candidates[i].eliminated = candidates[i].votes == min;
  }
  return;
}
