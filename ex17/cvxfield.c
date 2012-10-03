#include <stdlib.h>
#include "cvxfield.h"

static gboolean cvx_field_expose_event(GtkWidget* widget,
    GdkEventExpose event, gpointer user_data) {
  g_print("exposed!\n");
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
  retvar->canvas = canvas;

  return retvar;
}
