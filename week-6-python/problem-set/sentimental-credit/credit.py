# TODO
import re
import sys


def main():
    # Get the credit card number from the user
    number = get_number()

    # Calculate the checksum and check the validity of the credit card number
    checksum = calculate_checksum(number)

    # If the credit card number is valid, determine its type and print the result
    if checksum:
        print(credit_card(number))
    else:
        print("INVALID")


def get_number():
    while True:
        try:
            # Get user input for the credit card number
            number = input("Number: ")
            pattern = r"^(34|37|4[0-9]|5[0-5])([0-9]{11}|[0-9]{13}|[0-9]{14})$"
            if re.fullmatch(pattern, number):
                return number
            # Raise ValueError if the input does not match the pattern
            raise ValueError
        except ValueError:
            # Exit the program with an error message if the input is invalid
            sys.exit("INVALID")


def calculate_checksum(number):
    # Initialize variables to store the partial sums
    first_sum = 0
    second_sum = 0
    number_len = len(number)

    for i in range(number_len):
        # Get the digit from the rightmost position
        digit = int(number[number_len - 1 - i])

        # If the digit is at an even position from the right
        if i % 2 == 0:
            second_sum += digit
        # If the digit is at an odd position from the right
        else:
            digit *= 2
            first_sum += int(digit / 10 + digit % 10)

    # Calculate the checksum as the sum of the two partial sums
    checksum = first_sum + second_sum
    return checksum % 10 == 0


def credit_card(number):
    number_len = len(number)
    starting_digit = int(number[:2])

    # Check for American Express (AMEX) cards with 15 digits and starting digits 34 or 37
    if number_len == 15 and starting_digit in [34, 37]:
        return "AMEX"
    # Check for Visa cards with 13 or 16 digits and starting digits between 40 and 49
    elif number_len in [13, 16] and 40 <= starting_digit < 50:
        return "VISA"
    # Check for Mastercard cards with 16 digits and starting digits between 51 and 55
    elif number_len == 16 and 51 <= starting_digit <= 55:
        return "MASTERCARD"

    # Return INVALID if the card type is not recognized
    return "INVALID"


if __name__ == "__main__":
    main()
