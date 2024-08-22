#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *name;
  int votes;
} candidate;

int main(void)
{
  const int num_candidates = 3;
  candidate candidates[num_candidates];

  candidates[0].name = "Zidan";
  candidates[0].votes = 99;

  candidates[1].name = "Abra";
  candidates[1].votes = 85;

  candidates[2].name = "John";
  candidates[2].votes = 77;

  // Find the highest votes
  int highest_votes = 0;

  for (int i = 0; i < num_candidates - 1; i++)
  {
    if (candidates[i].votes > highest_votes)
    {
      highest_votes = candidates[i].votes;
    }
  }

  // Print name of candidate with highest votes
  for (int i = 0; i < num_candidates; i++)
  {
    if (candidates[i].votes == highest_votes)
    {
      printf("%s\n", candidates[i].name);
    }
  }

  return 0;
}
