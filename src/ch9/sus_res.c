// Julie Kim (julie114.kim@gmail.com)
// If a process whose user IDs all have the value X executes a set-user-ID
// program whose user ID, Y, is nonzero, then the process credentials are set as
// follows:
// real=X effective=Y saved=Y
// a) Suspend and resume the set-user-ID identity (i.e., switch the effective
// user ID to the value of the real user ID and then back to the saved set-user-ID)
#include <unistd.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  uid_t ruid, euid, suid;
  uid_t temp_uid;
  printf("Set dummy ruid:10, euid:1000\n");
  setreuid(10, 1000);
  getresuid(&ruid, &euid, &suid);
  printf("Initialized ids: ruid:%ld, euid:%ld, suid:%ld\n", (long) ruid, (long) euid, (long) suid);

  temp_uid = geteuid();
  if (temp_uid == -1) {
    errExit("geteuid()");
  }
  seteuid(ruid);
  printf("Set set-user-Id by ruid(suspend effective user)\n");
  getresuid(&ruid, &euid, &suid);
  printf("Current ids...ruid:%ld, euid:%ld, suid:%ld\n", (long) ruid, (long) euid, (long) suid);

  printf("Resume set-user-Id by previous effective user id :%ld\n", (long) temp_uid);
  seteuid(temp_uid);
  getresuid(&ruid, &euid, &suid);
  printf("Current ids...ruid:%ld, euid:%ld, suid:%ld\n", (long) ruid, (long) euid, (long) suid);

  exit(EXIT_SUCCESS);
}
