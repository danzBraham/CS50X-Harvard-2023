def main():
    scores = []
    for _ in range(3):
        scores.append(get_int("Score: "))

    average = sum(scores) / len(scores)
    print(f"Average: {average:.2f}")


def get_int(prompt):
    while True:
        try:
            n = int(input(prompt))
            if n < 1:
                continue
            return n
        except ValueError:
            pass


main()
