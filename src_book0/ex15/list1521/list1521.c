#include <uriparser/Uri.h>

/* range->first to range->afterLast */
static void print_info(const char* msg, struct UriTextRangeStructA* range) {
  printf("%s", msg);
  const char* ptr = range->first;
  while (range->afterLast != ptr) putchar(*ptr++);
  printf("\n");
}

int main (int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s URI\n", argv[0]);
    return 1;
  }

  UriParserStateA state;
  UriUriA uri;
  state.uri = &uri;
  if (uriParseUriA(&state, argv[1]) != URI_SUCCESS) {
    fprintf(stderr, "Cannot pare URI %s\n", argv[1]);
    return 1;
  }

  /* print scheme, userInfo, hostText, portText */
  print_info("Scheme = ", &uri.scheme);
  print_info("user = ", &uri.userInfo);
  print_info("host = ", &uri.hostText);
  print_info("port = ", &uri.portText);

  /* print path */
  struct UriPathSegmentStructA* path;
  int i = 0;
  for (path = uri.pathHead; path != NULL; path = path->next, i++) {
    print_info(((i == 0) ? "path = " : "> "), &path->text);
  }

  /* print query and fragment */
  print_info("query = ", &uri.query);
  print_info("fragment =", &uri.fragment);

  uriFreeUriMembersA(&uri);

  return 0;
}
