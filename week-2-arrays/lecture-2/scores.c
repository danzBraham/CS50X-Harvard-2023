#include <cs50.h>
#include <stdio.h>

#define N 3

float average(int array[], int length);

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(scores, N));
}

float average(int array[], int length)
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += array[i];
    }
    return total / (float) length;
}
