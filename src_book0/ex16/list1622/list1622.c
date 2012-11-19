#include <stdlib.h>
#include <dmalloc.h>

int main() {
  char* a;
  int i;
  for (i = 0; i < 1; i++) {
    a = (char*) malloc(100);
    usleep(1);
  }
  return 0;
}
