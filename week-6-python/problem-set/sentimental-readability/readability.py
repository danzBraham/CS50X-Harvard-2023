# TODO
def main():
    text = get_text()

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    print(calculate_grades(letters, words, sentences))


def get_text():
    while True:
        # Get user input for the text
        text = input("Text: ")
        # Check if the text is not an empty string
        if len(text) > 0:
            return text


def count_letters(text):
    # Initialize a variable to store the count of letters
    letters = 0

    # Iterate each char in the text
    for char in text:
        # Check if char is letter or not
        if char.isalpha():
            # Increment letters
            letters += 1

    return letters


def count_words(text):
    # Initialize variable to store values
    words = 0
    in_word = False

    # Iterate each char in text
    for char in text:
        # Check if char is in word or not
        if not char.isspace() and not in_word:
            # Increment words
            words += 1
            in_word = True
        elif char.isspace():
            in_word = False

    return words


def count_sentences(text):
    # Initialize a variable to store the count of sentence
    sentences = 0

    # Iterate each char in text
    for i in range(len(text) - 1):
        # Check if current char is alnum and next char is ., !, or ?
        if text[i].isalnum() and text[i + 1] in [".", "!", "?"]:
            # Increment sentences
            sentences += 1

    return sentences


def calculate_grades(letters, words, sentences):
    # Calculate the percentage of letters and sentences relative to the number of words
    L = float(letters / words * 100)
    S = float(sentences / words * 100)

    # Calculate the Coleman-Liau index
    grade = 0.0588 * L - 0.296 * S - 15.8

    # Determine the grade level based on the calculated index and then return
    if grade < 1:
        return "Before Grade 1"
    elif grade >= 16:
        return "Grade 16+"
    else:
        return f"Grade {round(grade)}"


if __name__ == "__main__":
    main()
