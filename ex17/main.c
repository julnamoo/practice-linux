#include "cvxfield.h"

#define CVX_MAIN_TITLE  "main_window"
#define CVX_MAIN_WIDTH  400
#define CVX_MAIN_HEIGHT 300

int main(int argc, char* argv[]) {
  GtkWidget* window;
  CvxField* field;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(GTK_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  field = cvx_field_new(GTK_WINDOW(window),
      CVX_MAIN_TITLE, CVX_MAIN_WIDTH, CVX_MAIN_HEIGHT);
  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}
