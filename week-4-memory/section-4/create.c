#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for improper usage, otherwise, get filename length
    if (argc != 2)
    {
        printf("Wrong usage: Try ./create [filename]\n");
        return 1;
    }

    // Open new file under the name stored at filename
    FILE *new_file = fopen(argv[1], "w");
    if (new_file == NULL)
    {
        printf("Could not create file.\n");
        return 1;
    }

    fclose(new_file);

    return 0;
}