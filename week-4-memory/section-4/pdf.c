#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Check input
    if (argc != 2)
    {
        printf("Usage: ./pdf file_name\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");

    // Check if file exist
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer[4];
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, file);

    // Check the signature
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Your file is not PDF!\n");
            fclose(file);

            return 0;
        }
    }
    printf("Your file is PDF!\n");

    // Close file
    fclose(file);

    return 0;
}
