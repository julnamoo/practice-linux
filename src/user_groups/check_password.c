// Julie Kim (julie114.kim@gmail.com)
// Authenticate user with shadow password
#define _BSD_SOURCE
#define _XOPEN_SOURCE
#include <unistd.h>
#include <limits.h>
#include <pwd.h>
#include <shadow.h>
#include "../lib/tlpi_hdr.h"

int main (int argc, char** argv) {
  char *username, *password, *encrypted, *p;
  struct passwd* pwd;
  struct spwd* shdpwd;
  Boolean authOk;
  size_t len;
  long lnmax;

  lnmax = sysconf(_SC_LOGIN_NAME_MAX);
  if (lnmax == -1) {
    lnmax = 256;
  }

  username = malloc(lnmax);
  if (username == NULL) {
    errExit("malloc");
  }

  printf("Username:");
  fflush(stdout);
  if (fgets(username, lnmax, stdin) == NULL) {
    exit(EXIT_FAILURE);
  }

  len = strlen(username);
  if (username[len-1] == '\n') {
    username[len-1] = '\0';
  }

  pwd = getpwnam(username);
  if (pwd == NULL) {
    fatal("couldn't get password record");
  }
  shdpwd = getspnam(username);
  if (shdpwd == NULL && errno == EACCES) {
    fatal("no permission to read shadow password file");
  }

  if (shdpwd != NULL) {
    pwd->pw_passwd = shdpwd->sp_pwdp;
  }
  password = getpass("Password: ");
  encrypted = crypt(password, pwd->pw_passwd);
  /* erase pasword after crypt() */
  for (p = password; *p != '\0';) {
    *p++ = '\0';
  }

  if (encrypted == NULL) {
    errExit("crypt");
  }
  authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
  if (!authOk) {
    printf("Incorrect password\n");
    exit(EXIT_FAILURE);
  }

  printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);
  exit(EXIT_SUCCESS);
}
