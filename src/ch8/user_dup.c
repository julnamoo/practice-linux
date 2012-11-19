// Julie Kim (julie114.kim@gmail.com)
// Figure out why it prints the same user id when it intends to print two user
// names from each ids.
#include <pwd.h>
#include "../lib/tlpi_hdr.h"

int main (int argc, char** argv) {
  struct passwd* user1;
  struct passwd* user2;
  user1 = getpwnam("julie");
  if (user1 == NULL) {
    errExit("couldn't get password record for julie");
  }

  user2 = getpwnam("hadoop");
  if (user2 == NULL) {
    errExit("couldn't get password record for hadoop");
  }
  printf("%ld %ld\n", (long) user1->pw_uid, (long) user2->pw_uid);
  return 0;
}
