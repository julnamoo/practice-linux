#include <gtk/gtk.h>

int main(int argc, char* argv[]) {
  GtkWidget* window;

  // Initialize
  gtk_init(&argc, &argv);

  // configure window
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(window);

  // event loop
  gtk_main();

  return 0;
}
