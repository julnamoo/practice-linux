// Julie Kim (julie114.kim@gmail.com)
// Example of interaction between compiler optimization and longjmp()
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf env;

static void doJump(int nvar, int rvar, int vvar) {
  printf("inside doJump(): nvar=%d rvar=%d vvar=%d\n", nvar, rvar, vvar);
  longjmp(env, 1);
}

int main(int argc, char** argv) {
  int nvar;
  register int rvar; // Allocate to register if it can
  register int vvar;

  nvar = 111;
  rvar = 222;
  vvar = 333;

  /* Run afger setjmp(0 */
  if (setjmp(env) == 0) {
    nvar = 777;
    rvar = 888;
    vvar = 999;
    doJump(nvar, rvar, vvar);
  }else {
    printf("After longjmp(): nvar=%d, rvar=%d, vvar=%d\n", nvar, rvar, vvar);
  }

  exit(EXIT_SUCCESS);
}
