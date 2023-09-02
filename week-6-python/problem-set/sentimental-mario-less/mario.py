# TODO
def main():
    # Get height from the user and then print the mario pyramid
    mario(get_height())


def get_height():
    """
    Get the height of the Mario pyramid from the user.
    The height must be an integer between 1 and 8 (inclusive).
    """
    while True:
        try:
            # Get user input for height
            height = int(input("Height: "))
            # Check if height is within the valid range
            if 0 < height < 9:
                return height
        except ValueError:
            pass


def mario(height):
    """
    Print a Mario pyramid of the given height.
    """
    # Loop from 1 to the height (inclusive)
    for i in range(1, height + 1):
        # Print the row with spaces and blocks
        print(" " * (height - i), "#" * i, sep="")


if __name__ == "__main__":
    main()
