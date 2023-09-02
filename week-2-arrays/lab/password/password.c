// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    // Get password from user
    string password = get_string("Enter your password: ");

    // Check if the password is valid
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number, and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // Initialize variables to track the presence of different character types
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    // Get the length of the password
    int pass_length = strlen(password);

    // Iterate through each character of the password
    for (int i = 0; i < pass_length; i++)
    {
        if (isupper(password[i]))
        {
            upper = true;
        }
        if (islower(password[i]))
        {
            lower = true;
        }
        if (isdigit(password[i]))
        {
            number = true;
        }
        if (ispunct(password[i]))
        {
            symbol = true;
        }
    }

    // Return true if all character types are present, otherwise false
    return (upper && lower && number && symbol);
}
