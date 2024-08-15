#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 19 // Maximum digits in a credit card number
#define MIN_DIGITS 13 // Minimum digits in a valid credit card number

long long get_long_long(const char *prompt);
int calculate_checksum(long long number);
int get_digit_length(long long number);
int is_credit_card_number_valid(long long number);
void print_credit_card(long long number);

int main(void)
{
  long long credit_card_number = get_long_long("Number: ");
  if (credit_card_number == -1)
  {
    fprintf(stderr, "Failed to get valid input.\n");
    return 1;
  }

  if (is_credit_card_number_valid(credit_card_number))
  {
    print_credit_card(credit_card_number);
  }
  else
  {
    printf("INVALID\n");
  }

  return 0;
}

long long get_long_long(const char *prompt)
{
  char buffer[MAX_DIGITS + 2]; // +2 for newline and null terminator
  char *endptr;
  long long number;

  while (1)
  {
    printf("%s", prompt);
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
      return -1; // Error or EOF
    }

    // Remove newline if exists
    buffer[strcspn(buffer, "\n")] = '\0';

    // Check if input is all digits
    int is_valid = 1;
    for (int i = 0; buffer[i]; i++)
    {
      if (!isdigit(buffer[i]))
      {
        is_valid = 0;
        break;
      }
    }

    if (!is_valid)
    {
      continue;
    }

    number = strtoll(buffer, &endptr, 10);

    if (*endptr == '\0' && number > 0)
    {
      return number;
    }
  }
}

int calculate_checksum(long long number)
{
  int sum = 0;
  int alternate = 0;

  while (number > 0)
  {
    int digit = number % 10;
    if (alternate)
    {
      digit *= 2;
      if (digit > 9)
      {
        digit = (digit / 10) + (digit % 10);
      }
    }
    sum += digit;
    alternate = !alternate;
    number /= 10;
  }

  return sum % 10 == 0;
}

int get_digit_length(long long number)
{
  int digit_length = 0;
  while (number > 0)
  {
    number /= 10;
    digit_length++;
  }
  return digit_length;
}

int is_credit_card_number_valid(long long number)
{
  int digit_length = get_digit_length(number);
  return (digit_length >= MIN_DIGITS && digit_length <= MAX_DIGITS && calculate_checksum(number));
}

void print_credit_card(long long number)
{
  int digit_length = get_digit_length(number);
  // Get first two digits
  while (number >= 100)
  {
    number /= 10;
  }

  if (digit_length == 15 && (number == 34 || number == 37))
  {
    printf("AMEX\n");
  }
  else if (digit_length == 16 && number >= 51 && number <= 55)
  {
    printf("MASTERCARD\n");
  }
  else if ((digit_length == 13 || digit_length == 16) && (number /= 10) == 4)
  {
    printf("VISA\n");
  }
  else
  {
    printf("INVALID\n");
  }
}
