#include <stdio.h>

void main(int argc, char *argv[])
{
  int i;
  for(i = 1; i < argc; i++) {
  	  printf("‘æ %d ˆø” : %s\n", i, argv[i]);
  }
}