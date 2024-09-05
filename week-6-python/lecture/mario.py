def main():
    height = get_int("Height: ")
    mario(height)
    return


def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
            if n < 1:
                continue
            return n
        except ValueError:
            pass


def mario(n):
    for _ in range(n):
        print("#" * n)


main()
