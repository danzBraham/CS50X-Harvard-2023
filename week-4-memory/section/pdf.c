#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./pdf pdf_file\n");
    return 1;
  }

  FILE *f = fopen(argv[1], "rb");
  if (f == NULL)
  {
    printf("File not found\n");
    return 2;
  }

  BYTE buffer[4];

  fread(buffer, sizeof(BYTE), 4, f);

  if (buffer[0] != 37 && buffer[1] != 80 && buffer[2] != 68 && buffer[3] != 70)
  {
    printf("File is not PDF\n");
    fclose(f);
    return 3;
  }

  printf("File is PDF\n");
  fclose(f);
  return 0;
}