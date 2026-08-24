#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  // int opt;
  //   if ((opt = getopt_long(argc, argv, "--execute")) == -1)
  if (argc > 1 && strcmp(argv[1], "--execute") == 0)
  {
    //  switch (opt)
    //  {
    //  case ('execute'):
    //    break;
    //  default:
    fprintf(stderr, " usage :  %s  [--execute] to execute\n  ", argv[0]);
    printf("\n");
    return 1;
    //  }
  }

  // printf("\n %d", opt);
  printf("\n it will execute\n  ");

  printf("\n");
  return 0;
}
