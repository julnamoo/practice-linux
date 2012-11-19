// Julie Kim (julie114.kim@gmail.com)
// Problem5-6. After several writes call, check final file and figuring out what
// is the cause.
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int fd1, fd2, fd3;

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s fpath\n", argv[0]);
  }

  fd1 = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
  if (fd1 == -1) {
    errExit("open");
  }
  printf("opened fd:%d\n", fd1);

  fd2 = dup(fd1);
  fd3 = open(argv[1], O_RDWR);
  write(fd1, "Hello,", 6);
  write(fd2, "world", 6);
  lseek(fd2, 0, SEEK_SET);
  write(fd1, "HELLO,", 6);
  write(fd3, "Gidday", 6);

  exit(EXIT_SUCCESS);
}

