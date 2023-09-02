#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_secret_phrase(string phrase);

int main(void)
{
    string phrase = get_string("What's the secret phrase? ");

    bool correct = check_secret_phrase(phrase);

    if (correct)
    {
        printf("Come on in!\n");
        return 0;
    }

    printf("Not Allowed!\n");
    return 1;
}

bool check_secret_phrase(string phrase)
{
    return (strcmp(phrase, "Please") == 0);
}