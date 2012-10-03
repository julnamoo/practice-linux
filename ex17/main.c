#include <gtk/gtk.h>

#define CVX_MAIN_TITLE  "main_window"
#define CVX_MAIN_WIDTH  400
#define CVX_MAIN_HEIGHT 300

int main(int argc, char* argv[]) {
  GtkWidget* window;
  GtkWidget* canvas;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(GTK_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  canvas = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), canvas);

  gtk_window_set_title(GTK_WINDOW(window), CVX_MAIN_TITLE);
  gtk_widget_set_size_request(GTK_WIDGET(window),
      CVX_MAIN_WIDTH, CVX_MAIN_HEIGHT);
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}
