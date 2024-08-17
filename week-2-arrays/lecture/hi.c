#include <stdio.h>

int main(void)
{
  char *words[2];

  // String (char *) is an array of characters
  words[0] = "HI!";
  words[1] = "BYE!";

  printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
  printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}