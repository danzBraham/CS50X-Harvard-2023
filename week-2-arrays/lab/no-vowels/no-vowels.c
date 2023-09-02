// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // Check for correct command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    // Replace vowels with numbers and print the result
    printf("%s\n", replace(argv[1]));
    return 0;
}

string replace(string word)
{
    int word_length = strlen(word);

    for (int i = 0; i < word_length; i++)
    {
        // Replace vowels with corresponding numbers using a switch statement
        switch (word[i])
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                // Keep other characters unchanged
                break;
        }
    }

    return word;
}
