// Julie Kim (julie114.kim@gmail.com)
// Open a file with O_APPEND flag and set offset at the first before write.
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int fd, flags;
  off_t off;

  if (argc != 3 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s pathname arg\n", argv[0]); 
  }

  fd = open(argv[1], O_APPEND|O_WRONLY, S_IRUSR|S_IWUSR);
  if (fd == -1) {
    errExit("open");
  }

  if (lseek(fd, 0, SEEK_SET) == -1) {
    errExit("lseek");
  }

  printf("arg length:%d\n", strlen(argv[2]));
  if (write(fd, argv[2], strlen(argv[2])) != strlen(argv[2])) {
    errExit("write");
  }
  exit(EXIT_SUCCESS);
}
