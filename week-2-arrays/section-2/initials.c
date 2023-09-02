#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Missing command-line argument!\n");
        return 1;
    }

    for (int i = 0; i < argc - 1; i++)
    {
        printf("%c", argv[i + 1][0]);
    }
    printf("\n");
}