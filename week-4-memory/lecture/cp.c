#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./cp src_file dest_file\n");
    return 1;
  }

  FILE *src = fopen(argv[1], "rb");
  FILE *dest = fopen(argv[2], "wb");

  BYTE b;

  while (fread(&b, sizeof(b), 1, src) != 0)
  {
    fwrite(&b, sizeof(b), 1, dest);
  }

  fclose(src);
  fclose(dest);
  return 0;
}