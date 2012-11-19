#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(char* cmd) {
  fprintf(stderr, "usage: \n");
  fprintf(stderr, "  %s -h  : show help\n", cmd);
  fprintf(stderr, "  %s -b  : say good-bye\n", cmd);
  fprintf(stderr, "  %s -n <name>: greeting to <name>\n", cmd);
}

int main(int argc, char* argv[]) {
  int opt;
  char* greeting = "Hello, ";
  char* target = "world";

  while ((opt = getopt(argc, argv, "bhn:")) != -1) {
    switch (opt) {
      case 'b':
        greeting = "Good-bye, ";
        break;
      case 'n':
        target = optarg;
        break;
      case 'h': /* fall-through */
      default:
        usage(argv[0]);
        return EXIT_FAILURE;
    }
  }
  printf("%s%s!\n", greeting, target);
  return EXIT_SUCCESS;
}
