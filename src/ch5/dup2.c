// Julie Kim (julie114.kim@gmail.com)
// Probrem5-4.2.Program mimics dup2() with fcntl() and close()
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int newfd, tempfd;

  if (argc != 3 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s oldfd newfd\n", argv[0]);
  }

  tempfd = atoi(argv[2]);
  // Check newFd is available
  if (fcntl(tempfd, F_GETFD) > 0) {
    if (close(tempfd) == -1) {
      errExit("close opened fd as newfd");
    }
  }
  newfd = fcntl(atoi(argv[1]), F_DUPFD, tempfd);
  printf("copied fd:%d\n", newfd);
  write(newfd, "hello", 5);
  return newfd;
}
