#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 5;
    int guess = get_int("What's your guess? ");

    if (guess != number)
    {
        printf("Wrong Guess!\n");
    }
    else
    {
        printf("You're Correct!\n");
    }
}