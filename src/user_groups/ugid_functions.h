// Julie Kim (julie114.kim@gmail.com)
#include <grp.h>

char* userNameFromId(uid_t uid);
uid_t userIdFromName(const char* name);

char* groupNameFromId(gid_t gid);
gid_t groupIdFromName(const char* name);

