def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(f"result: {x + y}")


def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass


main()
