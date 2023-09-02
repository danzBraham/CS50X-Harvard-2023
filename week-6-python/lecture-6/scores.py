def main():
    scores = []
    for i in range(3):
        score = get_int()
        # Method 1 using append
        scores.append(score)
        # Method 2 using temp list
        # scores += [score]

    average = sum(scores) / len(scores)
    print(f"Average: {average:.2f}")


def get_int():
    while True:
        try:
            x = int(input("Score: "))
            if x > 0:
                return x
        except ValueError:
            print("Not an integer")


main()