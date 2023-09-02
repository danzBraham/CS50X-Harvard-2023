#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover raw_image\n");
        return 1;
    }

    // Open memory card
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[512];
    int count = 0;
    char filename[8];

    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), 512, inptr) == 512)
    {
        // Check if the block starts a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous image file if it's open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new image file
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(inptr);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            // Increment the count for the next image file
            count++;
        }

        // Write the block to the current image file if it's open
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }

    // Close the last image file
    if (img != NULL)
    {
        fclose(img);
    }

    // Close the input file
    fclose(inptr);

    return 0;
}
