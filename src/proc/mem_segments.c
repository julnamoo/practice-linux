// Julie Kim (julie114.kim@gmail.com)
// Positioning of program variables in process memory segment
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];
int primes[] = {2, 3, 5, 7};

static int square(int x) {
  int result;   // allocated in squre() frame
  result = x*x; // allocated in squre() frame
  return result; // pass the result by register
}

static void doCalc(int val) {
  printf("The squrd of %d is %d\n", val, square(val));
  if (val < 10000) {
    int t;    // allocated in doCalc() frame
    t = val * val * val;
    printf("The Cube of %d is %d \n", val, t);
  }
}

int main (int argc, char** argv) {
  static int key = 9973; //initialized
  static char mbuf[10240000]; //ininitialized
  char *p; // allocated in main() frame

  p = malloc(1024);
  doCalc(key);

  exit(EXIT_SUCCESS);
}
