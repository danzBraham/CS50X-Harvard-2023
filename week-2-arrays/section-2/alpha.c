#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Missing command-line argument!\n");
        return 1;
    }

    // Get word
    string word = argv[1];

    // Get length of the word
    int word_length = strlen(word);

    for (int i = 0; i < word_length - 1; i++)
    {
        // Check if not alphabetical (i.e., "ba")
        if (word[i] > word[i + 1])
        {
            printf("No it's not alphabetical!\n");
            return 0;
        }
    }

    printf("Yes it's alphabetical!\n");
    return 0;
}
