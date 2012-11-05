// Julie Kim (julie114.kim@gmail.com)
// Pb6-2. What happend when calling longjmp() after return.
// A. Each doJump() and helloDoodle() calls longjmp().
// It is repected to display both of two message, "...from  doJump..." and
// "...from helloDoodle...". However, running it shows only one message,
// "...from helloDoodle...".
// setjmp() does not work correctly.
#include <setjmp.h>
#include "../lib/tlpi_hdr.h"

static jmp_buf env;

static void helloDoodle(int a, char* msg) {
  printf("Inside helloDoodle():a=%d, msg=%s", a, msg);
  longjmp(env, 2);
}

static void doJump(int a, int b, char* msg) {
  printf("Inside doJump():a=%d, b=%d, msg=%s", a, b, msg);
  if (a == 100) {
    helloDoodle(a*2, msg);
  } 
  longjmp(env, 1);
}

int main(int argc, char** argv) {
  int a = 100;
  int b = -100;
  
  switch(setjmp(env)) {
    case 0: 
      printf("Init setjmp(). It calls doJump() and returned...\n");
      doJump(a, b, "Hello jumping!\n");
      return;
    case 1:
      printf("Hello, I'm from doJump()!\n");
      return;
    case 2:
      printf("Hello, I'm from helloDoodle()!\n");
      return;
  }

  exit(EXIT_SUCCESS);
}
