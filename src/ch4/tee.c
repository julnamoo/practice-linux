// Julie Kim (julie114.kim@gmail.com)
// Practice 4-1: Implement 'tee' instruction using I/O system calls.
// It appends to the file instead of overwrite like 'tee -a file'
#include <ctype.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>

#include "../lib/tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char* argv[]) {
  int opt;
  int outputFd;
  ssize_t numRead, numWritten; 

  while ((opt = getopt(argc, argv, "a:")) != -1) {
    switch (opt) {
      case 'a':
        /* print stdin to stdout and append to file */
        outputFd = open(optarg, O_RDWR|O_CREAT|O_APPEND,
            S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

        break;
      default:
        /* print stdin to stdout and overwrite to file */
        outputFd = open(optarg, O_RDWR|O_CREAT|O_TRUNC,
            S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
        break;
    }

    if (outputFd == -1) {
      errExit("open");
    }
    while ((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
      if (write(outputFd, buf, numRead) != numRead) {
        fatal("couldn't write whole buffer to file");
      }

      if (write(STDOUT_FILENO, buf, numRead) != numRead) {
        fatal("couldn't write whole buffer to stdout");
      }
    }
  }
  if (numRead == -1)
    errExit("read");

  if (close(outputFd) == -1)
    errExit("close outputFd");

  exit(EXIT_SUCCESS);
}
