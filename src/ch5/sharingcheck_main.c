// Julie Kim (julie114.kim@gmail.com)
// Probrem5-5. Check sharing status of file offset and file status flag
// between oldfd and copied newfd. For this, argument is fpath to open and copy.
#include <fcntl.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int oldfd, newfd, old_v, new_v;

  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s fpath\n", argv[0]);
  }

  oldfd = open(argv[1], O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
  if (oldfd == -1) {
    errExit("open");
  }
  printf("opened fd:%d\n", newfd);

  newfd = fcntl(oldfd, F_DUPFD, 3);
  printf("copied fd:%d\n", newfd);
  write(newfd, "hello\n", 6);

  // Check sharing status
  // 1. file offset
  old_v = lseek(atoi(argv[1]), 0, SEEK_CUR);
  new_v = lseek(newfd, 0, SEEK_CUR);
  if (old_v == new_v) {
    printf("They are have the same offset:%d\n", new_v);
  } else {
    printf("They are different file offset...\n");
  }
  printf("old_v:%d, new_v:%d\n", old_v, new_v);

  printf("Check again after write operation to newfd..\n");
  write(newfd, "hello\n", 6);
  old_v = lseek(atoi(argv[1]), 0, SEEK_CUR);
  new_v = lseek(newfd, 0, SEEK_CUR);
  if (old_v == new_v) {
    printf("They are have the same offset:%d\n", new_v);
  } else {
    printf("They are different file offset...\n");
  }
  printf("old_v:%d, new_v:%d\n", old_v, new_v);

  // 2. open file status flags
  old_v = fcntl(atoi(argv[1]), F_GETFD);
  new_v = fcntl(newfd, F_GETFD);
  if (old_v == -1 || new_v == -1) {
    errExit("fcntl");
  }
  if (old_v == new_v) {
    printf("They have the sample flag value\n");
  } else {
    printf("They are different opened file flag value...\n");
  }

  if (close(oldfd) == -1) {
    errExit("close oldfd");
  }
  if (close(newfd) == -1) {
    errExit("close newfd");
  }
  exit(EXIT_SUCCESS);
}
