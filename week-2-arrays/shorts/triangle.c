#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float a = get_float("a: ");
    float b = get_float("b: ");
    float c = get_float("c: ");

    if (valid_triangle(a, b, c))
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }

}

bool valid_triangle(float a, float b, float c)
{
    // Check all positive real numbers
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    // Check one side must be larger than the other
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }

    return true;
}