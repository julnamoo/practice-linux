// Julie Kim (julie114.kim@gmail.com)
// Problem5-6.readv and writev by read, write and malloc packages.
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

ssize_t jreadv(int fd, const struct iovec *iov, int iovcnt) {
  int i;
  ssize_t read_len, total;
  total = 0;
  for (i = 0; i < iovcnt; ++i) {
    //char* buf = (char *) malloc(sizeof(char) * iov[i].iov_len);
    read_len = read(fd, iov[i].iov_base, iov[i].iov_len);
    total += read_len;
    if (read_len == -1) {
      errExitEN(-1, "jreadv.read");
    }
    // for checking EOF
    if (read_len < iov[i].iov_len) {
      return total;
    }
  }
  return total;
}

ssize_t jwritev(int fd, const struct iovec *iov, int iovcnt) {
  int i;
  ssize_t write_len, total;
  total = 0;
  for (i = 0; i < iovcnt; ++i) {
    write_len = write(fd, iov[i].iov_base, iov[i].iov_len);
    if (write_len == -1) {
      errExitEN(-1, "jwritev.write");
    }
    total += write_len;
  }
  return total;
}

int main(int argc, char** argv) {
  int fd;
  struct iovec iov[3];
  struct stat myStruct;
  int x;

#define STR_SIZE 100
  char str[STR_SIZE];
  ssize_t numRead, numWrite, totRequired;

  if (argc != 2 || strcmp(argv[1], "--help") == 0 ) {
    usageErr("%s file\n", argv[0]);
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    errExit("open");
  }
  totRequired = 0;
  iov[0].iov_base = &myStruct;
  iov[0].iov_len = sizeof(struct stat);
  totRequired += iov[0].iov_len;

  iov[1].iov_base = &x;
  iov[1].iov_len = sizeof(x);
  totRequired += iov[1].iov_len;

  iov[2].iov_base = str;
  iov[2].iov_len = STR_SIZE;
  totRequired += iov[2].iov_len;

  numRead = jreadv(fd, iov, 3);
  if (numRead == -1) {
    errExit("jreadv");
  }

  if (numRead < totRequired) {
    printf("Read fewer bytes than requested\n");
  }

  printf("total bytes requested: %ld;bytes read: %ld\n",
      (long) totRequired, (long) numRead);

  printf("Close exist fd and open or create newfile for writing contents in iov buffers\n");
  close(fd);

  fd = open("jwritev.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
  numWrite = jwritev(fd, iov, 3);
  if (numWrite == -1) {
    errExit("jwritev");
  }
  
  if (numWrite < totRequired) {
    printf("Write fewef bytes than requested\n");
  }
  printf("total bytes requested: %ld;bytes write: %ld\n",
      (long) totRequired, (long) numWrite);

  exit(EXIT_SUCCESS);
}
