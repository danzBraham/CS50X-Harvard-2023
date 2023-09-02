#include <stdio.h>

int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf("x is %i, y is %i\n", x, y);
}

int increment(int x)
{
    x++;
    return x;
}