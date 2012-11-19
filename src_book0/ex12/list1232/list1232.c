#include <glade/glade.h>
#include <stdlib.h>

#define GLADE_FILE "greeting.glade"
#define ROOT_WIDGET "window1"

void morning() {
  printf("Good morning!\n");
}

void afternoon() {
  printf("Good afternoon!\n");
}

void evening() {
  printf("Good evening!\n");
}

int main(int argc, char* argv[]) {
  GladeXML* xml;

  // Initialize
  gtk_init(&argc, &argv);
  if ((xml = glade_xml_new(GLADE_FILE, ROOT_WIDGET, NULL)) == NULL) {
    g_error("Can not load the interface data");
    exit(1);
  }

  glade_xml_signal_autoconnect(xml);
  gtk_widget_show_all(glade_xml_get_widget(xml, "window1"));

  /* event loop */
  gtk_main();

  return 0;
}
