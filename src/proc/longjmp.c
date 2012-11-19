// Julie Kim (julie114.kim@gmail.com)
// Example usage of setjmp() and longjmp()
#include <setjmp.h>
#include "../lib/tlpi_hdr.h"

static jmp_buf env;

static void f2 (void) {
  longjmp(env, 2);
}

static void f1 (argc) {
  if (argc == 1) {
    longjmp(env, 1);
  }
}

int main(int argc, char** argv) {
  switch (setjmp(env)) {
    case 0:
      printf("Calling f1() after initial setjmp()\n");
      f1(argc);
      break;

    case 1:
      printf("We jumped back from f1()\n");
      break;

    case 2:
      printf("We jumped back from f1()\n");
      break;
  }

  exit(EXIT_SUCCESS);
}
