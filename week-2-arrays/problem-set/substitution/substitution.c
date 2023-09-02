#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool check_26_characters(string key);
bool check_alphabetic(string key);
bool check_each_letter_once(string key);
char rotate(char c, string key);
string ciphertext(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check that the program was executed with only one command-line argument
    if (argc != 2)
    {
        printf("usage ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Check the validity of the command-line argument
    if (!check_26_characters(key) || !check_alphabetic(key) || !check_each_letter_once(key))
    {
        return 1;
    }

    // Get plaintext input from user
    string plaintext = get_string("plaintext: ");

    // Print the resulting ciphertext
    printf("ciphertext: %s\n", ciphertext(plaintext, key));

    return 0;
}

bool check_26_characters(string key)
{
    // Check that the key must contain exactly 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return false;
    }

    return true;
}

bool check_alphabetic(string key)
{
    int length = strlen(key);

    for (int i = 0; i < length; i++)
    {
        // Check that the key must be alphabetic
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic\n");
            return false;
        }
    }

    return true;
}

bool check_each_letter_once(string key)
{
    int length = strlen(key);

    for (int i = 1; i < length; i++)
    {
        // Check that each letter appears exactly once in the key
        for (int j = 0; j < i; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Key must contain each letter exactly once\n");
                return false;
            }
        }
    }

    return true;
}

char rotate(char c, string key)
{
    if (!isalpha(c))
    {
        return c;
    }

    char cipher;

    if (isupper(c))
    {
        cipher = toupper(key[c - 'A']);
    }
    else
    {
        cipher = tolower(key[c - 'a']);
    }

    return cipher;
}

string ciphertext(string plaintext, string key)
{
    int plaintext_length = strlen(plaintext);

    // Encrypt each character in the plaintext using the key
    for (int i = 0; i < plaintext_length; i++)
    {
        plaintext[i] = rotate(plaintext[i], key);
    }

    return plaintext;
}
