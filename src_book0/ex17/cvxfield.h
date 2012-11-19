#ifndef __CVX_FIELD_H__
#define __CVX_FIELD_H__

#include <gtk/gtk.h>

G_BEGIN_DECLS

typedef struct _CvxField CvxField;

#include "cvxnode.h"

struct _CvxField {
  GtkWindow* window;
  GtkWidget* canvas;

  CvxNode* node;
  gboolean in_operation;
};

CvxField* cvx_field_new(GtkWindow* window,
    gchar* title, guint width, guint height);

G_END_DECLS

#endif // __CVX_FIELD_H__
