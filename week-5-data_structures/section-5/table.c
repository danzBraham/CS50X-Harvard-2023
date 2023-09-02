#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26];

int hash(string phrase);
void print_hash(void);
void free_memory(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");
        int index = hash(phrase);
    }

    print_hash();
    free_memory();
}

char* strdup(const char* str)
{
    size_t len = strlen(str) + 1;
    char* new_str = malloc(len);
    if (new_str != NULL)
    {
        memcpy(new_str, str, len);
    }
    return new_str;
}


// TODO: return an index, 0–25, for a given phrase
int hash(string phrase)
{
    if (phrase == NULL)
    {
        printf("Invalid input.\n");
        return -1;
    }

    int first_char = toupper(phrase[0]);

    if (!isalpha(first_char))
    {
        printf("Invalid input: First character muan alphabet.\n");
        return -1;
    }

    int index = first_char - 'A';

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Could not allocate memory.\n");
        return -1;
    }

    n->phrase = strdup(phrase);

    if (table[index] == NULL)
    {
        n->next = NULL;
    }
    else
    {
        n->next = table[index];
    }

    table[index] = n;

    return index;
}

void print_hash(void)
{
    for (int i = 0; i < 26; i++)
    {
        node *current_node = table[i];
        while (current_node != NULL)
        {
            printf("from hash %i: %s\n", i, current_node->phrase);
            current_node = current_node->next;
        }
    }
}

void free_memory(void)
{
    for (int i = 0; i < 26; i++)
    {
        node *current_node = table[i];
        while (current_node != NULL)
        {
            node *tmp = current_node;
            current_node = current_node->next;
            free(tmp->phrase);
            free(tmp);
        }
        table[i] = NULL;
    }
}
