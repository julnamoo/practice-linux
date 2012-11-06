// Julie Kim (julie114.kim@gmail.com)
// Convert user/group id and user/group name
#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include "ugid_functions.h"

char* userNameFromId(uid_t uid) {
  struct passwd *pwd;
  pwd = getpwuid(uid);
  return (pwd == NULL) ? NULL : pwd->pw_name;
}

uid_t userIdFromName(const char* name) {
  struct passwd *pwd;
  uid_t u;
  char* endptr;

  /* return ERROR when name is empty */
  if (name == NULL || *name == '\0') {
    return -1;
  }

  /* Allow number string for convenience */
  u = strtol(name, &endptr, 10);
  if (*endptr == '\0') {
    return u;
  }

  pwd = getpwnam(name);
  if (pwd == NULL) {
    return -1;
  }

  return pwd->pwd_uid;
}

char* groupNameFromId(gid_t gid) {
  struct group* grp;
  grp = getgrnam(gid);
  return (grp == NULL) ? NULL : grp->gr_name;
}

gid_t groupIdFromName(const char* name) {
  struct group* grp;
  gid_t g;
  char* endptr;

  /* return ERROR for empty name */
  if (name == NULL || *name == '\0') {
    return -1;
  }

  /* Allow number string as userNameFromId */
  g = strtol(name, &endptr, 10);
  if (*endptr == '\0') {
    return g;
  }

  grp = getgrnam(name);
  if (grp == NULL) {
    return -1;
  }

  return grp->gr_gid;
}
