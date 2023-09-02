#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    candidate candidates[3];

    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate();
        printf("%i. %s\n", i + 1, candidates[i].name);
    }
}

candidate get_candidate(void)
{
    printf("Make candidate: \n");

    candidate c;
    c.name = get_string("Name: ");
    c.votes = get_int("Votes: ");

    return c;
}
