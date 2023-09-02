#include <stdio.h>

int main(void)
{
    typedef struct car
    {
        int year;
        char *name;
        char *model;
    }`
    car_t;

    car_t cars[3];

    cars[0].year = 2000;
    cars[0].name = "GTR";
    cars[0].model = "Nissan";

    printf("%s\n", cars[0].model);
}