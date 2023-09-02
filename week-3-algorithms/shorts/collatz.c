#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Number: ");
    printf("%i steps\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
    {
        printf("%i\n", n);
        return 0;
    }
    else if (n % 2 == 0)
    {
        printf("%i, ", n);
        return 1 + collatz(n / 2);
    }

    printf("%i, ", n);
    return 1 + collatz(3 * n + 1);
}
