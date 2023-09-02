#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    // Get height
    int height = get_height();

    // Print pyramid
    print_pyramid(height);
}

// Prompt user for the height
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Print the pyramid
void print_pyramid(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // Print spaces before the left-side pyramid
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }

        // Print left-side pyramid
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }

        // Print gap between the pyramids
        printf("  ");

        // Print right-side pyramid
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
