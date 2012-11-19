#include "cvxfield.h"

#define CVX_MAIN_TITLE  "main_window"
#define CVX_MAIN_WIDTH  400
#define CVX_MAIN_HEIGHT 300
#define CVX_MAIN_BGCOLOR "White"

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

  {
    GdkColor color;
    GdkScreen* screen;

    gdk_color_parse(CVX_MAIN_BGCOLOR, &color);
    screen = gdk_display_get_default_screen(gdk_display_get_default());
    gdk_rgb_find_color(gdk_screen_get_rgb_colormap(screen), &color);
    gdk_window_set_background(field->canvas->window, &color);
  }

  gtk_main();
  return 0;
}
