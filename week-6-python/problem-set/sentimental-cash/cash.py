# TODO
from cs50 import get_float


def main():
    # Get the amount owed in cents (integer value)
    cents = get_cents()
    coins = 0

    while cents > 0:
        # Check for quarters (25 cents)
        if cents >= 25:
            cents -= 25
            coins += 1
        # Check for dimes (10 cents)
        elif cents >= 10:
            cents -= 10
            coins += 1
        # Check for nickels (5 cents)
        elif cents >= 5:
            cents -= 5
            coins += 1
        # Check for pennies (1 cent)
        elif cents >= 1:
            cents -= 1
            coins += 1

    print(coins)


def get_cents():
    while True:
        try:
            # Get user input for amount owed in dollars
            dollars = get_float("Change owed: ")
            if dollars > 0:
                # Convert dollars to cents and return as an integer
                return round(dollars * 100)
        except ValueError:
            pass


if __name__ == "__main__":
    main()
