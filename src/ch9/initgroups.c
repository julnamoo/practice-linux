// Julie Kim (julie114.kim@gmail.com)
// Implement initgroups() using setgroups() and library functions for retrieving
// information from the password and group files (Section 8.4). Remember that a
// process must be privileged in order to be able to call setgroups()
#define _BSD_SOURCE
#include <grp.h>
#include "../lib/tlpi_hdr.h"

#define MAX_GROUPS 65535

int main(int argc, char** argv) {
  struct group* group;
  gid_t new_groups[MAX_GROUPS];
  char** users;
  gid_t g;
  int i, j;

  if (argc < 3 || strcmp("--help", argv[1]) == 0
      || argv[1] == NULL) {
    usageErr("%s username groupid\n", argv[0]);
  }
  // Retrieving groups including the user. (Scannig /etc/groups)
  while ((group = getgrent()) != NULL) {
    users = group->gr_mem;
    for (i = 0, j = 0; users[i] != NULL; i++) {
      if (strcmp(argv[0], users[i]) == 0) {
        new_groups[j] = group->gr_gid;
        j += 1;
      }
    }
  }
  new_groups[j] = atol(argv[2]);
  j++;
  // Initialize groups of the process
  if (setgroups(j, new_groups) == -1) {
    errExit("setgroupos");
  }

  endgrent();
}
