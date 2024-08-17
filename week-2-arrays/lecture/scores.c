#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int N = 3;

int get_int(const char *prompt);
float average(int length, int array[]);

int main(void)
{
  int scores[N];
  for (int i = 0; i < N; i++)
  {
    scores[i] = get_int("score: ");
  }

  printf("%f\n", average(N, scores));
  return 0;
}

int get_int(const char *prompt)
{
  char buffer[5];
  char *endptr;
  int number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
      buffer[len - 1] = '\0';
    }
    else
    {
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
    }

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
}

float average(int length, int array[])
{
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / (float)length;
}
