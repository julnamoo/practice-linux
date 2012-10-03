#include <gmime/gmime.h>

int main (int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s MSG_FILE\n", argv[0]);
    return 1;
  }

  g_mime_init(0);

  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open the file %s\n", argv[1]);
    return 1;
  }

  GMimeStream* stream = g_mime_stream_file_new(fp);
  GMimeParser* parser = g_mime_parser_new_with_stream(stream);
  GMimeMessage* message = g_mime_parser_construct_message(parser);

  if (message == NULL) {
    fprintf(stderr, "Cannot construct message\n");
    return 1;
  }

  printf("Date    : %s\n", g_mime_message_get_date_as_string(message));
  printf("Subject : %s\n", g_mime_message_get_subject(message));
  printf("From    : %s\n", g_mime_message_get_sender(message));
  printf("To      : %s\n", internet_address_list_to_string(
        g_mime_message_get_all_recipients(message), FALSE));

  fclose(fp);
  return 0;
}
