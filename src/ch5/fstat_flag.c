// Julie Kim (julie114.kim@gmail.com)
// Example using fcntl() with file status flags.
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int fd;
  int flags, accessMode;

  fd = open("sample.txt", O_WRONLY);
  flags = fcntl(fd, F_GETFL);
  if (flags == -1) {
    errExit("fcntl");
  }

  if (flags & O_SYNC) {
    printf("writes are synchronized\n");
  }

  accessMode = flags & O_ACCMODE;
  if (accessMode == O_WRONLY || accessMode == O_RDWR) {
    printf("file is writable\n");
  }

  flags |= O_APPEND;
  if (fcntl(fd, F_SETFL, flags) == -1) {
    errExit("set fcntl");
  }

  exit(EXIT_SUCCESS);
}
