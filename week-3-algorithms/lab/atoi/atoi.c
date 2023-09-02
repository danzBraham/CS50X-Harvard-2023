#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
    return 0;
}

int convert(string input)
{
    // TODO
    // Base case: empty string
    if (input[0] == '\0')
    {
        return 0;
    }

    int length = strlen(input);

    // Convert the last character to its numeric value
    int n = input[length - 1] - '0';

    // Remove the last character from the string
    input[length - 1] = input[length];

    // Recursively calculate the value of the shortened string
    return n + (10 * convert(input));
}
