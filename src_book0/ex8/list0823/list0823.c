#include <stdio.h>
#include <sqlite3.h>

int callback(void* user_data, int argc, char** argv, char** field) {
  int i;
  int* counter = (int*) user_data;
  for (i = 0; i < argc; ++i) {
    printf("%s = %s\n", field[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");

  (*counter)++;
  return 0;
}

int main(int argc, char* argv[]) {
  sqlite3* db;
  char* err_msg = NULL;
  int rc;
  int counter = 0;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
    return 1;
  }

  rc = sqlite3_open_v2(argv[1], &db, SQLITE_OPEN_READONLY, NULL);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }
  
  rc = sqlite3_exec(db, argv[2], callback, &counter, &err_msg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", err_msg);
    sqlite3_free(db);
    sqlite3_close(db);
    return 1;
  }

  printf("%d callbacks(s).\n", counter);
  sqlite3_close(db);
  return 0;
}
