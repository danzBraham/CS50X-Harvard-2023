#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_int(const char *prompt);
int minimum_coins_for_change(int change);

int main(void)
{
  int change_owed = get_int("Change owed: ");
  if (change_owed == -1)
  {
    fprintf(stderr, "Failed to get input.\n");
    return 1;
  }

  printf("%i\n", minimum_coins_for_change(change_owed));

  return 0;
}

int get_int(const char *prompt)
{
  char buffer[3 + 2];
  char *endptr;
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    int is_valid = 1;
    for (int i = 0; buffer[i]; i++)
    {
      if (!isdigit(buffer[i]))
      {
        is_valid = 0;
        break;
      }
    }

    if (!is_valid)
    {
      continue;
    }

    number = (int)strtol(buffer, &endptr, 10);

    if (*endptr == '\0' && number > 0)
    {
      return number;
    }
  }

  return number;
}

int minimum_coins_for_change(int cents)
{
  int quarters = cents / 25;
  cents %= 25;

  int dimes = cents / 10;
  cents %= 10;

  int nickles = cents / 5;
  cents %= 5;

  int pennies = cents / 1;
  cents %= 1;

  return quarters + dimes + nickles + pennies;
}
