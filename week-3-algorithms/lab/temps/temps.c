// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    // Initialize city temperatures
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // Sort cities by temperature in descending order
    sort_cities();

    // Print average July temperatures by city
    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    avg_temp tmp;

    // Iterate over the array using bubble sort algorithm

    // Bubble Sort
    // for (int i = 0; i < NUM_CITIES - 1; i++)
    // {
    //     for (int j = 0; j < NUM_CITIES - 1 - i; j++)
    //     {
    //         // Compare temperatures and swap if necessary
    //         if (temps[j].temp < temps[j + 1].temp)
    //         {
    //             tmp = temps[j];
    //             temps[j] = temps[j + 1];
    //             temps[j + 1] = tmp;
    //         }
    //     }
    // }

    // Insertion Sort
    int i, key, j;
    for (i = 1; i < NUM_CITIES; i++)
    {
        key = temps[i].temp;
        j = i - 1;

        while (j >= 0 && temps[j].temp < key)
        {
            temps[j + 1].temp = temps[j].temp;
            j--;
        }

        temps[j + 1].temp = key;
    }
}
