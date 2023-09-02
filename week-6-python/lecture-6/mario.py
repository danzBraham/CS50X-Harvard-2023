def main():
    height = get_height()
    for i in range(height):
        # Method 1 using for
        # for j in range(height):
        #     print("#", end = "")
        # print()

        # Method 2 using * height
        print("#" * height)


def get_height():
    while True:
        try:
            x = int(input("Height: "))
            if x > 0:
                return x
        except ValueError:
            print("Not an integer")


main()