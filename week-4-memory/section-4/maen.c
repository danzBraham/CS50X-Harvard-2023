#include <stdio.h>

int main(void)
{
    int x = 7;
    int *p = &x;
    printf("p: %p\n", p);
    printf("i: %i\n", *p);
    *p = 77;
    printf("i: %i\n", x);
}