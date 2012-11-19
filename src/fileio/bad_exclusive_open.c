// Julie Kim (julie114.kim@gmail.com)
// A simple program using open() systemcall.
// If there are one more processes runinng it, they are can be on deadlock.
#include <fcntl.h>
#include <sys/stat.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  int fd;

  if (argc < 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s file\n", argv[0]);
  }

  fd = open(argv[1], O_WRONLY); 
  if (fd != -1) {
    printf("[PID %ld] File \"%s\" already exists\n", (long) getpid(), argv[1]);
    close(fd);
  } else {
    if (errno != ENOENT) { /* cannot finish the job with unknwon error */
      errExit("open");
    } else {
      /* probability fail point */
      printf("[PID %ld] File \"%s\" doesn't exist yet\n",
          (long) getpid(), argv[1]);
      sleep(5);
      printf("[PID %ld] Done sleeping...\n", (long) getpid());
      fd = open(argv[1], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
      if (fd == -1) {
        errExit("open");
      }

      printf("[PID %ls] Created file \"%s\" exclusively\n",
          (long) getpid(), argv[1]); /* It may be not true */
    }
  }
}
