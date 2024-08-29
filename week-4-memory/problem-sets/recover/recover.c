#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./recover FILE\n");
    return 1;
  }

  FILE *infile = fopen(argv[1], "r");
  if (infile == NULL)
  {
    printf("Could not open %s\n", argv[1]);
    return 1;
  }

  uint8_t buffer[BLOCK_SIZE];
  char filename[FILE_NAME_SIZE];
  int jpg_count = 0;
  FILE *outfile = NULL;

  while (fread(buffer, sizeof(uint8_t), BLOCK_SIZE, infile) == BLOCK_SIZE)
  {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
    {
      // Close previous file if open
      if (outfile != NULL)
      {
        fclose(outfile);
      }

      // Create new JPG file
      sprintf(filename, "%03i.jpg", jpg_count++);
      outfile = fopen(filename, "a");
      if (outfile == NULL)
      {
        printf("Could not create %s\n", filename);
        fclose(infile);
        fclose(outfile);
        return 1;
      }
    }

    if (outfile != NULL)
    {
      fwrite(buffer, sizeof(uint8_t), BLOCK_SIZE, outfile);
    }
  }

  fclose(infile);
  fclose(outfile);
  return 0;
}