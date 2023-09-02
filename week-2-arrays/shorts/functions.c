#include <cs50.h>
#include <stdio.h>

double mult_two_reals(double a, double b);
int add_two_ints(int a, int b);

int main(void)
{
    double a = get_double("a: ");
    double b = get_double("b: ");

    printf("result: %f\n", mult_two_reals(a, b));

    int c = get_int("c: ");
    int d = get_int("d: ");

    printf("result: %i\n", add_two_ints(c, d));
}

double mult_two_reals(double a, double b)
{
    return a * b;
}

int add_two_ints(int a, int b)
{
    return a + b;
}