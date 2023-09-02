#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    string phonenumber = get_string("What's your phone number? ");

    printf("Hello %s, you are %i years old. your phone number is %s\n", name, age, phonenumber);
}