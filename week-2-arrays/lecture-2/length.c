#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What's your name? ");

    // Manual
    // int n = 0;
    // while (name[n] != 0)
    // {
    //     n++;
    // }

    // Using string library
    int n = strlen(name);

    printf("Length: %i\n", n);
}