// Julie Kim (julie114.kim@gmail.com)
// unsetenv(const char* name):
// Remove environment variable from environ. It checks duplicate.
#include <stdlib.h>
#include <unistd.h>
#include "../lib/tlpi_hdr.h"

extern char** environ;

void printEnviron() {
  char** ep;

  for (ep = environ; *ep != NULL; ep++) {
    puts(*ep);
  }
}

int main(int argc, char** argv) {
  char** ep;
  char* var;

  if ((argc != 2) || (strcmp(argv[1], "--help")) == 0) {
    usageErr("%s name\n", argv[0]);
  }
  var = getenv(argv[1]);
  if (var == NULL) {
    printf("There is non like var..\n");
    return 0;
  }

  // Dup check
  for (ep = environ; *ep != NULL; ++ep) {
    if (strncmp(*ep, argv[1], strlen(argv[1])) == 0) {
      printf("Occur match..\n");
      *ep = *(ep+1);
    }
  }
  printEnviron();

  return 0;
}
