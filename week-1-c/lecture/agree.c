#include <stdio.h>

int main(void)
{
  char c;

  printf("Do you agree? ");
  scanf("%c", &c);

  if (c == 'Y' || c == 'y')
  {
    printf("yes, I am agree\n");
  }
  else if (c == 'N' || c == 'n')
  {
    printf("no, I am disagree\n");
  }

  return 0;
}