#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  // argc <= 1 ? 0 : argv[1];
  argv[1][0] == '\0' ? argv[0][1] = 0 : printf("\n");

  if (strcmp(argv[1], "--execute") != 0)
  {
    fprintf(stderr, " usage :  %s  [--execute] to execute\n  ", argv[0]);
    printf("\n");
    return 1;
  }

  printf("\n it will execute\n  ");

  printf("\n");
  return 0;
}
