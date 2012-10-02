#include <gpod/itdb.h>
#include <stdio.h>

/* display title */
static void print_title(gpointer data, gpointer user_data) {
  Itdb_Track* track = (Itdb_Track*) data;
  printf("%s\n", track->title);
}

int main(int argc, char* argv[]) {
  Itdb_iTunesDB* itdb;
  if (argc < 2) {
    fprintf(stderr, "Usage: %s MOUNT_POINT(iPod)\n", argv[0]);
    return 1;
  }

  /* get data from ipod */
  if ((itdb = itdb_parse(argv[1], NULL)) == NULL) {
    fprintf(stderr, "Cannot parse iTunesDB\n");
    return 1;
  }

  /* print titles */
  g_list_foreach(itdb->tracks, print_title, NULL);

  return 0;
}
