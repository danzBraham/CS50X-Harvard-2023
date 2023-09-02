// Practice writing a function to find a max value

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max = array[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        if (max < array[i])
        {
            // Update the maximum if a larger element is found
            max = array[i];
        }
    }

    return max;
}
