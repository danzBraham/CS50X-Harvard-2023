#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Input minimun
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Input maximum
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Iterate number of minimum to maximum
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // Check Number is not less than or equal to 1
    if (number <= 1)
    {
        return false;
    }

    // Check prime number
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
