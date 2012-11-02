// Julie Kim (julie114.kim@gmail.com)
// Probrem5-3.1.Program mimics dup() with fcntl()
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int newfd;

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s oldfd\n", argv[0]);
  }

  newfd = fcntl(atoi(argv[1]), F_DUPFD, 3);
  printf("copied fd:%d\n", newfd);
  write(newfd, "hello", 5);
  return newfd;
}
