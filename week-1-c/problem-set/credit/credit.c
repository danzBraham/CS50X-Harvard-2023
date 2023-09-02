#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Luhn's Algorithm

long get_number(void);
int get_number_length(long number);
int get_starting_digit(long number);
bool calculate_checksum(long number);
void print_credit_card(int number_length, int starting_digit);

int main(void)
{
    // Prompt for input
    long number = get_number();

    // Calculate checksum
    bool checksum = calculate_checksum(number);

    if (checksum)
    {
        // Check for card number length and starting digits
        int number_length = get_number_length(number);
        int starting_digit = get_starting_digit(number);

        // Print AMEX, MASTERCARD, VISA or INVALID
        print_credit_card(number_length, starting_digit);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_number(void)
{
    long n;
    do
    {
        n = get_long("Number: ");
    }
    while (n < 1);
    return n;
}

// Function to calculate the length of number
int get_number_length(long number)
{
    int number_length = 0;
    while (number > 0)
    {
        number /= 10;
        number_length++;
    }
    return number_length;
}

// Function to get the starting digit of number
int get_starting_digit(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return number;
}

// Function to calculate the checksum of the credit card number
bool calculate_checksum(long number)
{
    int first_sum = 0;
    int second_sum = 0;
    int length = get_number_length(number);

    for (int i = 0; i < length; i++)
    {
        // Extract each digit of the credit card number
        long digit = (number / (long) pow(10, i)) % 10;

        if (i % 2 == 0)
        {
            second_sum += digit;
        }
        else
        {
            digit *= 2;
            first_sum += digit / 10 + digit % 10;
        }
    }

    // Calculate the checksum by adding both sums
    int checksum = first_sum + second_sum;
    return (checksum % 10 == 0);
}

// Function to print the credit card type
void print_credit_card(int number_length, int starting_digit)
{
    if (number_length == 15 && (starting_digit == 34 || starting_digit == 37))
    {
        printf("AMEX\n");
    }
    else if ((number_length == 13 || number_length == 16) && (starting_digit >= 40 && starting_digit < 50))
    {
        printf("VISA\n");
    }
    else if (number_length == 16 && (starting_digit >= 51 && starting_digit <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
