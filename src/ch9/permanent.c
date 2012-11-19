// Julie Kim (julie114.kim@gmail.com)
// Permanently drop the set-user-ID identity (i.e., ensure that the effective
// user ID and the saved set-user-ID are set to the value of the real user ID).
#include <unistd.h>
#include "../lib/tlpi_hdr.h"

int main(int argc, char** argv) {
  uid_t ruid, euid, suid;
  printf("Set dummy ruid:10, euid:1000\n");
  setreuid(10, 1000);
  getresuid(&ruid, &euid, &suid);
  printf("Initialized ids >> ruid:%ld, euid:%ld, suid:%ld\n\n", (long) ruid, (long) euid, (long) suid);

  printf("Set suid as euid and suid by ruid %ld\n", (long) ruid);
  setresgid(ruid, euid, ruid);
  getresuid(&ruid, &euid, &suid);
  printf("Current ids >> ruid:%ld, euid:%ld, suid:%ld\n\n", (long) ruid, (long) euid, (long) suid);

  printf("Set euid(%ld) as ruid(%ld)\n", (long) euid, (long) ruid);
  setreuid(ruid, ruid);
  getresuid(&ruid, &euid, &suid);
  printf("Current ids >> ruid:%ld, euid:%ld, suid:%ld\n\n", (long) ruid, (long) euid, (long) suid);

  printf("Attemp to set euid as previous euid %ld\n", (long) euid);
  seteuid(euid);
  getresuid(&ruid, &euid, &suid);
  printf("Current ids >> ruid:%ld, euid:%ld, suid:%ld\n\n", (long) ruid, (long) euid, (long) suid);

  exit(EXIT_SUCCESS);
}
