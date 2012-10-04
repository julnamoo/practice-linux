#include <stdlib.h>
#include "cvxfield.h"

static gboolean cvx_field_expose_event(GtkWidget* widget,
    GdkEventExpose* event, gpointer user_data) {
  CvxField* field = (CvxField*) user_data;
  GdkWindow* drawable = widget->window;
  cairo_t* cr;

  gdk_window_clear(drawable);

  cr = gdk_cairo_create(drawable);
  cvx_polygon_render(field->polygon, cr);
  cvx_node_list_render(field->node_list, cr);
  cairo_destroy(cr);

  return FALSE;
}

static gboolean cvx_field_is_in_operation_p(CvxField* field) {
  return (field->active_node != NULL);
}

static void cvx_field_start_operation(CvxField* field, gint x, gint y,
    CvxNode* node) {
  field->active_node = node;
  cvx_node_set_difference(field->active_node, x, y);
}

static void cvx_field_finish_operation(CvxField* field, gint x, gint y) {
  field->active_node = NULL;
}

static void cvx_field_set_cursor(CvxField* field, gint x, gint y) {
  gboolean is_node;
  GdkCursorType cursor_type;
  GdkDisplay* display;
  GdkCursor* cursor;

  if (cvx_field_is_in_operation_p(field)) {
    cursor_type = GDK_FLEUR;
  } else {
    CvxNode* node = cvx_node_list_pick_node(field->node_list, x, y);
    cursor_type = (node != NULL) ? GDK_HAND1 : GDK_ARROW;
  }

  display = gdk_display_get_default();
  cursor = gdk_cursor_new_for_display(display, cursor_type);

  gdk_window_set_cursor(field->canvas->window, cursor);
}

static gboolean cvx_field_button_pressed(GtkWidget* widget,
    GdkEventButton* event, gpointer user_data) {
  gint x = event->x, y = event->y;
  CvxField* field = (CvxField*) user_data;
  CvxNode* node = cvx_node_list_pick_node(field->node_list, x, y);

  if (node != NULL) {
    cvx_field_start_operation(field, x, y, node);
    cvx_field_set_cursor(field, x, y);
  }

  return FALSE;
}

static gboolean cvx_field_button_released(GtkWidget* widget,
    GdkEventButton* event, gpointer user_data) {
  gint x = event->x, y = event->y;
  CvxField* field = (CvxField*) user_data;

  cvx_field_finish_operation(field, x, y);
  cvx_field_set_cursor(field, x, y);
  return FALSE;
}

static gboolean cvx_field_mouse_move(GtkWidget* widget,
    GdkEventMotion* event, gpointer user_data) {
  gint x = event->x, y = event->y;
  gint x0, y0, width, height, depth;
  CvxField* field = (CvxField*) user_data;
  GdkWindow* drawable = widget->window;

  gdk_window_get_geometry(drawable, &x0, &y0,
      &width, &height, &depth);
  if ((x < 0) || (y < 0) || (x >= width) || (y >= height)) {
    cvx_field_finish_operation(field, x, y);
  }

  if (cvx_field_is_in_operation_p(field)) {
    cvx_node_move_to(field->active_node, x, y);
    cvx_field_expose_event(widget, NULL, user_data);
  }

  cvx_field_set_cursor(field, x, y);
  return FALSE;
}

CvxField* cvx_field_new(GtkWindow* window,
    gchar* title, guint width, guint height) {
  CvxField* retvar;
  GtkWidget* canvas;

  retvar = (CvxField*) malloc(sizeof(CvxField));
  if (retvar == NULL) return NULL;

  gtk_window_set_title(window, title);
  gtk_widget_set_size_request(GTK_WIDGET(window), width, height);
  retvar->window = window;

  canvas = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), canvas);
  g_signal_connect(GTK_OBJECT(window), "expose-event",
      G_CALLBACK(cvx_field_expose_event), retvar);
  
  gtk_widget_set_events(canvas,
      GDK_BUTTON_PRESS_MASK |
      GDK_BUTTON_RELEASE_MASK |
      GDK_POINTER_MOTION_MASK);
  g_signal_connect(GTK_OBJECT(canvas), "motion-notify-event",
      G_CALLBACK(cvx_field_mouse_move), retvar);
  g_signal_connect(GTK_OBJECT(canvas), "button-press-event",
      G_CALLBACK(cvx_field_button_pressed), retvar);
  g_signal_connect(GTK_OBJECT(canvas), "button-release-event",
      G_CALLBACK(cvx_field_button_released), retvar);
  retvar->canvas = canvas;

  retvar->node_list = cvx_node_list_new(retvar, width, height);
  retvar->polygon = cvx_polygon_new(retvar, retvar->node_list->nodes);
  retvar->active_node = NULL;
  return retvar;
}
