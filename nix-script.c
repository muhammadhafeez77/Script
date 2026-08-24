#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  (void)argc;
  if (argv[1] == NULL)
  {
    argv[1] = argv[0];
  }

  if (strcmp(argv[1], "--execute") != 0)
  {
    fprintf(stderr, " usage :  %s  [--execute] to execute\n  ", argv[0]);
    printf("\n");
    _exit(1);
  }

  printf("\n it will execute\n  ");

  printf("\n");
  return 0;
}
