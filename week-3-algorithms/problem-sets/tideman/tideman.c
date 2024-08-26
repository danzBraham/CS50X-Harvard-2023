#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
  int winner;
  int loser;
} pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
char *get_string(const char *format, ...);
int get_int(const char *prompt);
bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool has_cycle(int winner, int loser);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char *argv[])
{
  // Check for invalid usage
  if (argc < 2)
  {
    printf("Usage: tideman [candidate ...]\n");
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
    candidates[i] = argv[i + 1];
  }

  // Clear graph of locked in pairs
  for (int i = 0; i < candidate_count; i++)
  {
    for (int j = 0; j < candidate_count; j++)
    {
      locked[i][j] = false;
    }
  }

  pair_count = 0;
  int voter_count = get_int("Number of voters: ");

  // Query for votes
  for (int i = 0; i < voter_count; i++)
  {
    // ranks[i] is voter's ith preference
    int ranks[candidate_count];

    // Query for each rank
    for (int j = 0; j < candidate_count; j++)
    {
      char *name = get_string("Rank %i: ", j + 1);

      if (!vote(j, name, ranks))
      {
        printf("Invalid vote.\n");
        return 3;
      }

      free(name);
    }

    record_preferences(ranks);

    printf("\n");
  }

  add_pairs();
  sort_pairs();
  lock_pairs();
  print_winner();

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

// Update ranks given a new vote
bool vote(int rank, char *name, int ranks[])
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    if (strcmp(name, candidates[i]) == 0)
    {
      ranks[rank] = i;
      return true;
    }
  }
  return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
  // TODO
  for (int i = 0; i < candidate_count - 1; i++)
  {
    for (int j = i + 1; j < candidate_count; j++)
    {
      preferences[ranks[i]][ranks[j]]++;
    }
  }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
  // TODO
  for (int i = 0; i < candidate_count - 1; i++)
  {
    for (int j = i + 1; j < candidate_count; j++)
    {
      if (preferences[i][j] > preferences[j][i])
      {
        pairs[pair_count].winner = i;
        pairs[pair_count].loser = j;
        pair_count++;
      }
      else if (preferences[i][j] < preferences[j][i])
      {
        pairs[pair_count].winner = j;
        pairs[pair_count].loser = i;
        pair_count++;
      }
    }
  }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
  // TODO
  for (int i = 0; i < pair_count - 1; i++)
  {
    for (int j = i + 1; j < pair_count; j++)
    {
      if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
      {
        pair tmp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = tmp;
      }
    }
  }
}

bool has_cycle(int winner, int loser)
{
  if (winner == loser)
  {
    return true;
  }
  for (int i = 0; i < candidate_count; i++)
  {
    if (locked[loser][i] && has_cycle(winner, i))
    {
      return true;
    }
  }
  return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
  // TODO
  for (int i = 0; i < pair_count; i++)
  {
    if (!has_cycle(pairs[i].winner, pairs[i].loser))
    {
      locked[pairs[i].winner][pairs[i].loser] = true;
    }
  }
}

// Print the winner of the election
void print_winner(void)
{
  // TODO
  for (int i = 0; i < candidate_count; i++)
  {
    bool is_source = true;
    for (int j = 0; j < candidate_count; j++)
    {
      if (locked[j][i])
      {
        is_source = false;
        break;
      }
    }
    if (is_source)
    {
      printf("%s\n", candidates[i]);
      return;
    }
  }
}
