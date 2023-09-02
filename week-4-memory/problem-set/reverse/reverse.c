#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input_file output_file\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile_name = argv[1];
    FILE *infile = fopen(infile_name, "r");
    if (infile == NULL)
    {
        printf("Could not open %s\n", infile_name);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(BYTE), sizeof(WAVHEADER), infile);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 1)
    {
        fclose(infile);
        printf("File format is not wav\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    char *outfile_name = argv[2];
    FILE *outfile = fopen(outfile_name, "w");
    if (outfile == NULL)
    {
        fclose(infile);
        printf("Could not open %s.\n", outfile_name);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(BYTE), sizeof(WAVHEADER), outfile);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    int16_t buffer[block_size];
    fseek(infile, -block_size, SEEK_END);

    while (ftell(infile) >= sizeof(WAVHEADER))
    {
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
        if (fseek(infile, -2 * block_size, SEEK_CUR))
        {
            return 1;
        }
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE format[] = {'W', 'A', 'V', 'E'};

    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != format[i])
        {
            return 1;
        }
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}