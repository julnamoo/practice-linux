#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (strcmp(argv[0], "./foo") == 0) {
    printf("Hello, Foo!\n");
  } else {
    printf("Hello, Bar!\n");
  }
  return 0;
}
