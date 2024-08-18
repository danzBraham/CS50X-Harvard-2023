#include <stdio.h>
#include <stdbool.h>

float mult_two_reals(float a, float b);
int add_two_ints(int a, int b);
bool valid_triangle(double a, double b, double c);

int main(void)
{
  printf("%.2f\n", mult_two_reals(2.3, 4.7));
  printf("%i\n", add_two_ints(2, 4));

  if (valid_triangle(5, 6, 2))
  {
    printf("VALID\n");
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}

float mult_two_reals(float a, float b)
{
  return a * b;
}

int add_two_ints(int a, int b)
{
  return a + b;
}

bool valid_triangle(double a, double b, double c)
{
  if (a <= 0 || b <= 0 || c <= 0)
  {
    return false;
  }

  if ((a + b <= c) || (b + c <= a) || (c + a <= b))
  {
    return false;
  }

  return true;
}