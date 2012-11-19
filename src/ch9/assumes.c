// Julie Kim (julie114.kim@gmail.com)
// Assume in each of the following cases that the initial set of process user
// IDs is
// real=1000 effective=0 saved=0 file-system=0. What would be the state of the
// user IDs
// after the following calls?
// a) setuid(2000);
// b) setreuid(–1, 2000);
// c) seteuid(2000);
// d) setfsuid(2000);
// e) setresuid(–1, 2000, 3000);
#include "../lib/tlpi_hdr.h"
#include <sys/fsuid.h>
#include <unistd.h>

void printfIds(uid_t fsuid) {
  uid_t ruid, euid, suid;
  getresuid(&ruid, &euid, &suid);
  printf("real user id: %ld\n", (long) ruid);
  printf("effective user id: %ld\n", (long) euid);
  printf("saved user id : %ld\n", (long) suid);
  printf("file system user id: %ld\n", (long) fsuid);
}

int main(int argc, char** argv) {
  printf("Example 9-1\n");
  uid_t fsuid, cur_fsuid;
  fsuid = 0;
  printf("Set intial condition, ruid:1000, euid:0, suid:0, fsuid:0\n");
  setresuid(1000, 0, 0);
  cur_fsuid = setfsuid(fsuid);
  printf("Initial user ids:\n");
  printfIds(cur_fsuid);

  setuid(2000);
  printf("After setuid(2000)\n");
  printfIds(cur_fsuid);

  setreuid(-1, 2000);
  printf("After setreuid(-1, 2000)\n");
  printfIds(cur_fsuid);

  seteuid(2000);
  printf("After seteuid(2000)\n");
  printfIds(cur_fsuid);

  cur_fsuid = setfsuid(2000);
  printf("After setfsuid(2000)\n");
  printfIds(cur_fsuid);

  setresuid(-1, 2000, 3000);
  printf("After setresuid(-1, 2000, 3000)\n");
  printfIds(cur_fsuid);

  exit(EXIT_SUCCESS);
}
