// Julie Kim (julie114.kim@gmail.com)
// Printing enviroment variables
#include "../lib/tlpi_hdr.h"

extern char** environ;

int main (int argc, char** argv) {
  char** ep;

  for (ep = environ; *ep != NULL; ep++) {
    puts(*ep);
  }

  exit(EXIT_SUCCESS);
}
