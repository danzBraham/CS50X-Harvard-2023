#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char buffer[8];
  sprintf(buffer, "%i.jpg", 100);
  printf("%s\n", buffer);
}