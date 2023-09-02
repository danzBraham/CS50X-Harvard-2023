#include <cs50.h>
#include <stdio.h>

unsigned long factorial(unsigned long n);

int main(void)
{
    unsigned long n = get_long("Number: ");

    printf("%lu\n", factorial(n));
}

unsigned long factorial(unsigned long n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
