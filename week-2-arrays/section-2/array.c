#include <cs50.h>
#include <stdio.h>

int get_length(void);
void print_array(int length);

int main(void)
{
    // Get length of array
    int length = get_length();

    // Print the array per element
    print_array(length);
}

int get_length(void)
{
    int n;
    do
    {
        n = get_int("Length: ");
    }
    while (n < 1);
    return n;
}

void print_array(int length)
{
    // Create an array of that length
    int pow[length];

    for (int i = 0; i < length; i++)
    {
        // Each element is 2 times the previous one and start at 1
        if (i == 0)
        {
            pow[i] = i + 1;
        }
        else
        {
            pow[i] = pow[i - 1] * 2;
        }
        printf("%i\n", pow[i]);
    }
}