#include <cs50.h>
#include <stdio.h>

int get_valid_int(string prompt, int min);

int main(void)
{
    // TODO: Prompt for start size
    int start = get_valid_int("Start size: ", 9);

    // TODO: Prompt for end size
    int end = get_valid_int("End size: ", start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start < end)
    {
        start += (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int get_valid_int(string prompt, int min)
{
    int value;
    do
    {
        value = get_int("%s", prompt);
    }
    while (value < min);
    return value;
}
