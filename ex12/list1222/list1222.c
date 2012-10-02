#include <gtk/gtk.h>

#define LABEL_WIDTH 200
#define LABEL_HEIGHT 50

int main(int argc, char* argv[]) {
  GtkWidget* window;
  GtkWidget* label;

  // Initialize
  gtk_init(&argc, &argv);

  // configure window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  // add label
  label = gtk_label_new("Hello, world!");
  gtk_widget_set_size_request(label, LABEL_WIDTH, LABEL_HEIGHT);
  gtk_container_add(GTK_CONTAINER(window), label);

  gtk_widget_show_all(window);


  // event loop
  gtk_main();

  return 0;
}
