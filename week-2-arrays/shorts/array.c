#include <stdio.h>

int set_int(int x);
int set_array(int array[4]);

int main(void)
{
    int a = 10;
    int b[4] = {0, 1, 2, 3};

    set_int(a);
    set_array(b);

    printf("%i %i\n", a, b[0]);
}

int set_int(int x)
{
    x = 22;
    return x;
}

int set_array(int array[4])
{
    array[0] = 22;
    return array[0];
}
