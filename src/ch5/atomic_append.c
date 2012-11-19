// Julie Kim (julie114.kim@gmail.com)
// Showing reason of atomic write with O_APPEND flag.
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int fd;
  
  if (argc < 3 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s filename num-bytes [x]\n", argv[0]);
  }

  if (strcmp(argv[3], "x") == 0) {
    fd = open(argv[1], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    printf("open without O_APPEND flag\n");
    lseek(fd, 0, SEEK_END);
  } else {
    fd = open(argv[1], O_APPEND|O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    printf("open with O_APPEND flag\n");
  }
  
  if (fd == -1) {
    errExit("open");
  }

  if (write(fd, " ", atol(argv[2])) != atoi(argv[2])) {
    errExit("write");
  }

  exit(EXIT_SUCCESS);
}
