#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    // int i = get_int("i: ");
    // int j = get_int("j: ");

    // char c = get_char("c: ");
    // char d = get_char("d: ");

    // if (s == t)
    // if (*s == *t)
    // if (strcmp(s, t) == 0)s
    // if (i == j)
    // if (c == d)
    // {
    //     printf("s: %p\n", &s);
    //     printf("t: %p\n", &t);

    //     // printf("i: %p\n", &i);
    //     // printf("j: %p\n", &j);

    //     // printf("c: %p\n", &c);
    //     // printf("d: %p\n", &d);

    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("s: %p\n", &s);
    //     printf("t: %p\n", &t);

    //     // printf("i: %p\n", &i);
    //     // printf("j: %p\n", &j);

    //     // printf("c: %p\n", &c);
    //     // printf("d: %p\n", &d);

    //     printf("Different\n");
    // }

    printf("%p\n", s);
    printf("%p\n", t);
}
