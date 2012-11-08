// Julie Kim (julie114.kim@gmail.com)
// getpwnam(const char* name) with setpwent(), getpwent(), and endpwent().
#include <pwd.h>
#include "../lib/tlpi_hdr.h"

struct passwd* jgetpwnam(const char* name) {
  struct passwd* user;
  for (user = getpwent(); user != NULL; user = getpwent()) {
    if (strcmp(name, user->pw_name) == 0) {
      setpwent();
      endpwent();
      return user;
    }
  }
}

void print_passwd(const struct passwd* user) {
  if (user == NULL) {
    errExit("print passwd");
  }

  printf("Username: %s\n", user->pw_name);
  printf("Userid: %ld\n", (long) user->pw_uid);
  printf("Groupid: %ld\n", (long) user->pw_gid);
  printf("RealName: %s\n", user->pw_gecos);
  printf("HomeDirectory: %s\n", user->pw_dir);
}

int main (int argc, char** argv) {
  struct passwd* user;
  if (argc != 2 || strcmp(argv[1], "--help") == 0) {
    usageErr("%s username\n", argv[0]);
  }

  user = jgetpwnam(argv[1]);
  print_passwd(user);
  return 0;
}
