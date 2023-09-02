#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

string get_text(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void print_grade(int words, int letters, int sentences);

int main(void)
{
    // Get input string from user
    string text = get_text();

    // Count number of letters
    int letters = count_letters(text);

    // Count number of words
    int words = count_words(text);

    // Count number of sentences
    int sentences = count_sentences(text);

    // Print the result
    print_grade(letters, words, sentences);
}

// Prompt the user
string get_text(void)
{
    string s;
    do
    {
        s = get_string("Text: ");
    }
    while (s[0] < 1);
    return s;
}

// Count the number of letters in the given text
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Count the number of words in the given text
int count_words(string text)
{
    int words = 0;
    bool in_word = false;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isspace(text[i]) && !in_word)
        {
            words++;
            in_word = true;
        }
        else if (isspace(text[i]))
        {
            in_word = false;
        }
    }

    return words;
}

// Count the number of sentences in the given text
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!ispunct(text[i]) && (text[i + 1] == '.' || text[i + 1] == '!' || text[i + 1] == '?'))
        {
            sentences++;
        }
    }

    return sentences;
}

// Print the grade based on Coleman-Liau index formula
void print_grade(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(grade));
    }
}
