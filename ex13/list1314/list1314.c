#include <gtk/gtk.h>
#include <cairo/cairo.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 300
#define LINE_WIDTH 10
#define BGCOLOR "White"

typedef struct { double x, y; } Node;

static GList* nodelist = NULL;

static gboolean repaint(GtkWidget* widget) {
  GList* node = nodelist;
  gdk_window_clear(widget->window);

  if (node != NULL) {
    cairo_t* cr = gdk_cairo_create(widget->window);
    double x = ((Node*) node->data)->x;
    double y = ((Node*) node->data)->y;

    /* configure line */
    cairo_set_line_width(cr, LINE_WIDTH);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
    cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.5); // navy

    /* draw see sight */
    cairo_move_to(cr, x, y);
    cairo_line_to(cr, x, y);

    /* draw turning line */
    while ((node = g_list_next(node)) != NULL) {
      x = ((Node*)node->data)->x;
      y = ((Node*)node->data)->y;
      cairo_line_to(cr, x, y);
    }

    /* drawing and terminating */
    cairo_stroke(cr);
    cairo_destroy(cr);
  }

  return FALSE;
}

static gboolean pressed(GtkWidget* widget, GdkEventButton* event) {
  Node* newnode;
  if((newnode = (Node*) malloc(sizeof(Node))) == NULL) {
    g_error("Not enough memory\n");
    exit(1);
  }

  /* add poits */
  newnode->x = event->x;
  newnode->y = event->y;
  nodelist = g_list_append(nodelist, newnode);

  repaint(widget);
  return FALSE;
}

static void set_background(GtkWidget* widget, const char* color_name) {
  GdkColor color;
  GdkDisplay* display = gdk_display_get_default();
  GdkScreen* screen = gdk_display_get_default_screen(display);
  GdkColormap* cmap = gdk_screen_get_rgb_colormap(screen);

  /* set bakcground from color map */
  gdk_color_parse(color_name, &color);
  gdk_rgb_find_color(cmap, &color);
  gdk_window_set_background(widget->window, &color);
}

int main(int argc, char* argv[]) {
  GtkWidget* window;
  GtkWidget* canvas;

  /* Init */
  gtk_init(&argc, &argv);

  /* set window */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(GTK_WIDGET(window), WIDTH, HEIGHT);
  gtk_signal_connect(GTK_OBJECT(window), "destroy",
      G_CALLBACK(gtk_main_quit), NULL);

  /* add canvas */
  canvas = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), canvas);
  gtk_signal_connect(GTK_OBJECT(canvas), "expose-event",
      G_CALLBACK(repaint),  NULL);
  gtk_signal_connect(GTK_OBJECT(canvas), "button-press-event",
      G_CALLBACK(pressed), NULL);

  /* add mouse event */
  gtk_widget_set_events(canvas, GDK_BUTTON_PRESS_MASK);
  gtk_widget_show_all(window);

  /* set background white */
  set_background(canvas, BGCOLOR);

  /* event loop */
  gtk_main();

  return 0;
}
