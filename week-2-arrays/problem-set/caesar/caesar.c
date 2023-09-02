#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Verify that the program was executed with only one command-line argument
    if (argc != 2)
    {
        printf("usage ./caesar key\n");
        return 1;
    }

    // Ensure that every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("usage ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string representation to an integer value
    int key = atoi(argv[1]);

    // Ask the user to provide the plaintext input
    string plaintext = get_string("plaintext: ");

    // For each character in the plaintext:
    int plaintext_length = strlen(plaintext);

    for (int i = 0; i < plaintext_length; i++)
    {
        // Apply a rotation (if applicable) to the character, considering its letter status
        plaintext[i] = rotate(plaintext[i], key);
    }

    // Print ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

bool only_digits(string key)
{
    int key_length = strlen(key);

    for (int i = 0; i < key_length; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int n)
{
    // Check if the char is alphabet or not
    if (!isalpha(c))
    {
        return c;
    }

    // Ensure rotation within the range of 26 letters
    n %= 26;

    if (isupper(c))
    {
        if (c + n > 'Z')
        {
            // Wrap around to the beginning of uppercase letters
            return 'A' + ((c + n) - 'Z' - 1);
        }
    }
    else
    {
        if (c + n > 'z')
        {
            // Wrap around to the beginning of lowercase letters
            return 'a' + ((c + n) - 'z' - 1);
        }
    }

    // Rotate the character
    return c + n;
}
