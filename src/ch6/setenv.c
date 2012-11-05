// Julie Kim (julie114.kim@gmail.com)
// setenv(const char* name, const char* value, int overwrite):
// Allocate new memory buffer for new env var and copy as 'name=value' format.
// If overwrite is set to 0, it does not overwrite.
#include <fcntl.h>
#include <sys/stat.h>
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
  char* old_vars;
  char* value;
  int overwrite, len, fd;
  pid_t pid;

  if (argc != 4 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s name value overwrite\n", argv[0]);
  }
  // 1. Check existence of the variable
  overwrite = atoi(argv[3]);
  old_vars = getenv(argv[1]);
  len = strlen(argv[1]) + strlen(argv[2]) + 1;
  value = (char*) malloc(sizeof(char) * len);
  strcpy(value, argv[1]);
  strcat(value, "=");
  strcat(value, argv[2]);

  // 2. If it doesn't exist then set tham and return.
  if (old_vars == NULL) {
    if (putenv(value) == 0) {
      printf("old var is empty, set env as %s\n", value);
      printEnviron();
      return 0;
    } else {
      errExit("putenv");
    }
  }
  
  // 3. If it exist and non-overwrite, return
  // 4. If it exist and overwrite then set them and return
  if (overwrite == 0) {
    printf("do not set env as %s\n", value);
    printEnviron();
    return 0;
  } else {
    if(putenv(value) == 0) {
      printf("set env as %s\n", value);
      printEnviron();
      return 0;
    } else {
      errExit("putenv");
    }
  }
}
