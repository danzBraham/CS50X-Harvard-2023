#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get input message from user
    string message = get_string("Message: ");
    int message_length = strlen(message);

    // Convert each character in the message to its binary representation
    int bits[BITS_IN_BYTE];

    for (int i = 0; i < message_length; i++)
    {
        // Extract individual bits from the character
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            bits[j] = message[i] % 2;
            message[i] /= 2;
        }

        // Print the binary representation of the character
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            print_bulb(bits[k]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
