#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: ./volume input.wav output.wav factor\n");
    return 1;
  }

  FILE *input = fopen(argv[1], "rb");
  if (input == NULL)
  {
    printf("Could not open file.\n");
    return 2;
  }

  FILE *output = fopen(argv[2], "wb");
  if (output == NULL)
  {
    printf("Could not open file.\n");
    return 3;
  }

  float factor = atof(argv[3]);

  uint8_t buffer[HEADER_SIZE];

  fread(buffer, sizeof(uint8_t), HEADER_SIZE, input);
  fwrite(buffer, sizeof(uint8_t), HEADER_SIZE, output);

  int16_t sample;

  while (fread(&sample, sizeof(int16_t), 1, input) != 0)
  {
    sample *= factor;
    fwrite(&sample, sizeof(uint16_t), 1, output);
  }

  fclose(input);
  fclose(output);
  return 0;
}